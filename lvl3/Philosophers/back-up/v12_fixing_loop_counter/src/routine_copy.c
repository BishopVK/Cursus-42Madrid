/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/16 20:57:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int id, char *action, t_table *table)
{
	int			loop_ended;
	static int	nbr_dies;

	pthread_mutex_lock(&table->end_mutex);
	loop_ended = table->loop_end;
	pthread_mutex_unlock(&table->end_mutex);
	if (!loop_ended)
	{
		pthread_mutex_lock(&table->print_mutex);
		if (nbr_dies == 0)
			printf("%ld: %d %s\n", get_current_time() - table->start_time, id, action);
		if (ft_strcmp(action, "died") == 0)
			nbr_dies++;
		pthread_mutex_unlock(&table->print_mutex);
	}
}

static int	end_of_routine(t_table *table)
{
	int		i;
	int		nbr_meals;
	long	time_restant;

	pthread_mutex_lock(&table->global_mutex);
	nbr_meals = table->total_meals;
	pthread_mutex_unlock(&table->global_mutex);
	pthread_mutex_lock(&table->end_mutex);
	if (table->loop_end)
	{
		pthread_mutex_unlock(&table->end_mutex);
		//printf("Entré LOL!\n");
		if (table->nbr_philos == 1)
			print_action(1, "died", table);
		//printf("Salí LOL!\n");
		return (true);
	}
	if (nbr_meals == table->nbr_philos * table->nbr_must_eat)
	{
		table->loop_end = true;
		pthread_mutex_unlock(&table->end_mutex);
		pthread_mutex_lock(&table->print_mutex);
		printf("Done %i loops correctly\n", nbr_meals);
		pthread_mutex_unlock(&table->print_mutex);
		return (true);
	}
	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_lock(&table->global_mutex);
		time_restant = get_current_time() - table->philos[i].last_meal_time;
		pthread_mutex_unlock(&table->global_mutex);
		if (time_restant > table->time_to_die)
		{
			table->philos[i].im_die = true;
			pthread_mutex_unlock(&table->end_mutex);
			print_action(table->philos[i].id, "died", table);
			return (true);
		}
		i++;
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
}

void	*referee_routine(void *arg)
{
	t_table	*table;
	int		i;
	int		someone_dies;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		while(i < table->nbr_philos)
		{
			pthread_mutex_lock(&table->end_mutex);
			someone_dies = table->philos[i].im_die;
			pthread_mutex_unlock(&table->end_mutex);
			if (someone_dies == true)
			{
				ft_usleep(1000);
				pthread_mutex_lock(&table->end_mutex);
				table->loop_end = true;
				pthread_mutex_unlock(&table->end_mutex);
				return (NULL);
			}
			i++;
		}
		/* someone_dies = table->im_die;
		pthread_mutex_unlock(&table->end_mutex); */
		/* if (table->im_die == true)
		{
			//pthread_mutex_lock(&table->end_mutex);
			table->loop_end = true;
			break ;
		}
		pthread_mutex_unlock(&table->end_mutex); */
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->table->nbr_philos == 3 && philo->id == 3)
		ft_usleep(philo->table->even_delay);
	else if (philo->id % 2 == 0)
		ft_usleep(philo->table->even_delay);
	while (end_of_routine(philo->table) == false)
	{
		if (end_of_routine(philo->table) == true)
		{
			printf("DB: 1\n");
			break ;
		}
		take_forks(philo);
		if (end_of_routine(philo->table) == true)
		{
			printf("DB: 2\n");
			leave_forks(philo);
			break ;
		}
		eat(philo);
		if (end_of_routine(philo->table) == true)
		{
			leave_forks(philo);
			printf("DB: 3\n");
			break ;
		}
		leave_forks(philo);
		if (end_of_routine(philo->table) == true)
		{
			printf("DB: 4\n");
			break ;
		}
		sleep_philosopher(philo);
		if (end_of_routine(philo->table) == true)
		{
			printf("DB: 5\n");
			break ;
		}
		think(philo);
	}
	return (NULL);
}
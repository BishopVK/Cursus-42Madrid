/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/16 17:46:38 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int id, char *action, t_table *table)
{
	printf("%ld: %d %s\n", get_current_time() - table->start_time, id, action);
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
		if (table->nbr_philos == 1)
			print_action(1, "died", table);
		return (pthread_mutex_unlock(&table->end_mutex), true);
	}
	if (nbr_meals == table->nbr_philos * table->nbr_must_eat)
	{
		table->im_die = true;
		printf("Done %i loops correctly\n", nbr_meals);
		return (pthread_mutex_unlock(&table->end_mutex), true);
		//return (1);
	}
	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_lock(&table->global_mutex);
		time_restant = get_current_time() - table->philos[i].last_meal_time;
		pthread_mutex_unlock(&table->global_mutex);
		if (time_restant > table->time_to_die)
		{
			table->im_die = true;
			//pthread_mutex_lock(&table->global_mutex);
			print_action(table->philos[i].id, "died", table);
			//pthread_mutex_unlock(&table->global_mutex);
			return (pthread_mutex_unlock(&table->end_mutex), true);
			//return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
}

void	*referee_routine(void *arg)
{
	t_table	*table;
	//int		someone_dies;

	table = (t_table *)arg;
	while (1)
	{
		pthread_mutex_lock(&table->end_mutex);
		/* someone_dies = table->im_die;
		pthread_mutex_unlock(&table->end_mutex); */
		if (table->im_die == true)
		{
			//pthread_mutex_lock(&table->end_mutex);
			table->loop_end = true;
			pthread_mutex_unlock(&table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->end_mutex);
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
			break ;
		take_forks(philo);
		if (end_of_routine(philo->table) == true)
		{
			leave_forks(philo);
			break ;
		}
		eat(philo);
		if (end_of_routine(philo->table) == true)
		{
			leave_forks(philo);
			break ;
		}
		leave_forks(philo);
		if (end_of_routine(philo->table) == true)
			break ;
		sleep_philosopher(philo);
		if (end_of_routine(philo->table) == true)
			break ;
		think(philo);
	}
	return (NULL);
}

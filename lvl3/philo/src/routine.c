/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/12 09:56:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int id, char *action, long start_time)
{
	printf("%ld: %d %s\n", get_current_time() - start_time, id, action);
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
			print_action(1, "died", table->start_time);
		return (pthread_mutex_unlock(&table->end_mutex), 1);
	}
	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_lock(&table->global_mutex);
		time_restant = get_current_time() - table->philos[i].last_meal_time;
		pthread_mutex_unlock(&table->global_mutex);
		if (time_restant > table->time_to_die)
		{
			table->loop_end = 1;
			print_action(table->philos[i].id, "died", table->start_time);
			//pthread_mutex_unlock(&table->global_mutex);
			return (pthread_mutex_unlock(&table->end_mutex), 1);
			//return (1);
		}
		/* pthread_mutex_lock(&table->global_mutex); // DB
		printf("DB: meals =%i\n", meals);
		pthread_mutex_unlock(&table->global_mutex); // DB */
		if (nbr_meals == table->nbr_philos * table->nbr_must_eat)
		{
			table->loop_end = true;
			printf("Done %i loops correctly\n", table->philos[i].meals_eaten);
			return (pthread_mutex_unlock(&table->end_mutex), 1);
			//return (1);
		}
		/* if (table->nbr_must_eat != -1 && table->philos[i].meals_eaten >= table->nbr_must_eat)
		{
			table->loop_end = 1;
			printf("Done %i loops correctly\n", table->philos[i].meals_eaten);
			return (pthread_mutex_unlock(&table->end_mutex), 1);
			//return (1);
		} */
		i++;
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
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
		pthread_mutex_lock(&philo->table->global_mutex);
		philo->table->total_meals++;
		pthread_mutex_unlock(&philo->table->global_mutex);
		if (end_of_routine(philo->table) == true)
		{
			leave_forks(philo);
			break ;
		}
		leave_forks(philo);
		if (end_of_routine(philo->table) == true)
			break ;
		sleep_philosopher(philo);
		think(philo);
	}
	return (NULL);
}

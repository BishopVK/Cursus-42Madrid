/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/02 08:25:24 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int id, char *action, long start_time)
{
	printf("%ld: %d %s\n", get_current_time() - start_time, id, action);
}

static int	end_of_routine(t_table *table)
{
	int	i;

	pthread_mutex_lock(&table->end_mutex);
	if (table->loop_end)
		return (pthread_mutex_unlock(&table->end_mutex), 1);
	i = 0;
	while (i < table->nbr_philos)
	{
		if (get_current_time() - table->philos[i].last_meal_time > table->time_to_die)
		{
			print_action(table->philos[i].id, "died", table->start_time);
			table->loop_end = 1;
			pthread_mutex_unlock(&table->end_mutex);
			return (1);
		}
		if (table->nbr_must_eat != -1 && table->philos[i].meals_eaten >= table->nbr_must_eat)
		{
			table->loop_end = 1;
			pthread_mutex_unlock(&table->end_mutex);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (end_of_routine(philo->table) == false)
	{
		think(philo);
		if (end_of_routine(philo->table) == true)
			break ;
		take_forks(philo);
		if (end_of_routine(philo->table) == true)
		{
			leave_forks(philo);
			break ;
		}
		eat(philo);
		leave_forks(philo);
		if (end_of_routine(philo->table) == true)
			break ;
		sleep_philosopher(philo);
	}
	return (NULL);
}

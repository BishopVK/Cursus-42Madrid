/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/03 14:18:12 by danjimen         ###   ########.fr       */
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
			table->loop_end = 1;
			pthread_mutex_lock(&table->global_mutex);
			print_action(table->philos[i].id, "died", table->start_time);
			pthread_mutex_unlock(&table->global_mutex);
			return (pthread_mutex_unlock(&table->end_mutex), 1);
		}
		if (table->nbr_must_eat != -1 && table->philos[i].meals_eaten >= table->nbr_must_eat)
		{
			table->loop_end = 1;
			pthread_mutex_lock(&table->global_mutex);
			printf("Done %i loops correctly\n", table->philos[i].meals_eaten);
			pthread_mutex_unlock(&table->global_mutex);
			return (pthread_mutex_unlock(&table->end_mutex), 1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
}

void	*referee_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;

	while (1)
	{
		if (table->is_simulation_ended == 1)
			table->loop_end = 1;
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	/* if (philo->table->nbr_philos == 3 && philo->id == 3)
		usleep(philo->table->even_delay); */
	/* if (philo->id % 2 == 0)
		usleep(philo->table->even_delay); */
	while (end_of_routine(philo->table) == 0)
	{
		take_forks(philo);
		leave_forks(philo);
		eat(philo);
		leave_forks(philo);
		sleep_philosopher(philo);
		think(philo);
	}
	return (NULL);
}

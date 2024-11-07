/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/05 12:02:11 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int id, char *action, long start_time)
{
	printf("%ld: %d %s\n", get_current_time() - start_time, id, action);
}

static int	end_of_routine(t_table *table, int meals)
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
			print_action(table->philos[i].id, "died", table->start_time);
			return (pthread_mutex_unlock(&table->end_mutex), 1);
			//return (1);
		}
		printf("meals =%i\n", meals);
		if (meals == table->nbr_philos * table->nbr_must_eat)
		{
			table->loop_end = 1;
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
	static int		meals;

	philo = (t_philosopher *)arg;
	if (philo->table->nbr_philos == 3 && philo->id == 3)
		usleep(philo->table->even_delay);
	else if (philo->id % 2 == 0)
		usleep(philo->table->even_delay);
	while (end_of_routine(philo->table, meals) == false)
	{
		//think(philo);
		if (end_of_routine(philo->table, meals) == true)
			break ;
		take_forks(philo);
		if (end_of_routine(philo->table, meals) == true)
		{
			leave_forks(philo);
			break ;
		}
		meals += eat(philo);
		leave_forks(philo);
		if (end_of_routine(philo->table, meals) == true)
			break ;
		sleep_philosopher(philo);
		think(philo);
	}
	return (NULL);
}

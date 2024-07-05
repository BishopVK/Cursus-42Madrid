/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/05 11:43:53 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	custom_sleep(int microseconds, t_philosopher *philo)
{
	int	interval;
	int	slept;

	interval = philo->table->even_delay * 1000;
	slept = 0;
	while (slept < microseconds)
	{
		if (microseconds - slept > interval)
			usleep(interval);
		else
			usleep(microseconds - slept);
		slept += interval;

		// Verificar si hemos sido interrumpidos
		pthread_mutex_lock(&philo->table->global_mutex);
		if (end_of_routine(philo->table) == true)
		{
			pthread_mutex_unlock(&philo->table->global_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->global_mutex);
	}
}

void	print_action(t_philosopher *philo, char *action)
{
	long	actual_time;

	actual_time = get_current_time() - philo->table->start_time;
	if (philo->table->loop_end == 0)
		printf("%ld: %d %s\n", actual_time, philo->id, action);

}

int	end_of_routine(t_table *table)
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
			//print_action(table->philos, "died");
			printf("%ld: %d %s\n", get_current_time() - table->start_time, table->philos[i].id, "died");
			return (pthread_mutex_unlock(&table->end_mutex), true);
			//return (1);
		}
		if (table->nbr_must_eat != -1 && table->philos[i].meals_eaten >= table->nbr_must_eat)
		{
			table->loop_end = 1;
			printf("Done %i loops correctly\n", table->philos[i].meals_eaten);
			return (pthread_mutex_unlock(&table->end_mutex), true);
			//return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (false);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->table->nbr_philos == 3 && philo->id == 3)
		usleep(philo->table->even_delay);
	else if (philo->id % 2 == 0)
		usleep(philo->table->even_delay);
	while (end_of_routine(philo->table) == false)
	{
		//think(philo);
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
		think(philo);
	}
	return (NULL);
}

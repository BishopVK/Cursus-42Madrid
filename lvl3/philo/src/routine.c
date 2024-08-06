/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/08/05 18:28:03 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* void	custom_sleep(int microseconds, t_philosopher *philo)
{
	int	interval;
	int	slept;

	//interval = philo->table->even_delay * 1000;
	interval = 100 * 1000;
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
} */

void	print_action(t_philosopher *philo, char *action)
{
	long	actual_time;

	actual_time = get_current_time() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
		printf("%ld: %d %s\n", actual_time, philo->id, action);
	pthread_mutex_unlock(&philo->table->end_mutex);
}

int	end_of_routine(t_table *table)
{
	int	i;
	long	current;
	long	time_since_last_meal;
	long	time_remaining;

	pthread_mutex_lock(&table->end_mutex);
	if (table->loop_end)
		return (pthread_mutex_unlock(&table->end_mutex), 1);
	i = 0;
	while (i < table->nbr_philos)
	{
		current = get_current_time() - table->start_time;
		time_since_last_meal = (table->philos[i].last_meal_time - current - table->start_time) * -1;
		time_remaining = table->time_to_die - time_since_last_meal;

		printf("ROUTINE: Philo == %i\n", i + 1);
		printf("ROUTINE: current == %li\n", current);
		printf("ROUTINE: time_since_last_meal == %li\n", time_since_last_meal);
		printf("ROUTINE: time_remaining == %li\n", current);

		if (time_remaining < table->time_to_eat)
		{
			printf("ADIOS!!!\n");
			//usleep(time_remaining * 1000);
			table->loop_end = 1;
			printf("%ld: %d %s\n", get_current_time() - table->start_time, table->philos[i].id, "died");
			return (pthread_mutex_unlock(&table->end_mutex), true);
		}

		/* if (get_current_time() - table->philos[i].last_meal_time)
		{
			table->loop_end = 1;
			printf("table->philos[i].last_meal_time - current= %li\n", table->philos[i].last_meal_time - current);
			usleep(table->time_to_die - current * -1);
			printf("%ld: %d %s\n", get_current_time() - table->start_time, table->philos[i].id, "died");
			return (pthread_mutex_unlock(&table->end_mutex), true);
		} */

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

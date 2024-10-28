/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/28 08:00:14 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philosopher *philo)
{
	if (philo->table->loop_end == 0)
		print_action(philo->id, "is thinking", philo->table->start_time);
}

void	eat(t_philosopher *philo)
{
	if (philo->table->loop_end == 0)
		print_action(philo->id, "is eating", philo->table->start_time);
	usleep(philo->table->time_to_eat * 1000);
	philo->meals_eaten++;
	philo->last_meal_time = get_current_time(); // Need to protect whit mutex (data race detected)
}

void	sleep_philosopher(t_philosopher *philo)
{
	if (philo->table->loop_end == 0)
		print_action(philo->id, "is sleeping", philo->table->start_time);
	usleep(philo->table->time_to_sleep * 1000);
}

/* void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	if (philo->id % 2 == 0)
	{
		while (1)
		{
			pthread_mutex_lock(&philo->table->global_mutex); // Lock the global mutex to check forks availability
			pthread_mutex_lock(&philo->table->forks[left_fork]);
			if (pthread_mutex_lock(&philo->table->forks[right_fork]) == 0)
			{
				pthread_mutex_unlock(&philo->table->global_mutex); // Unlock the global mutex as we have taken both forks
				if (philo->table->loop_end == 0)
					print_action(philo->id, "has taken a fork", philo->table->start_time);
				if (philo->table->loop_end == 0)
					print_action(philo->id, "has taken a fork", philo->table->start_time);
				return ; // Both forks taken, exit the function
			}
			else
			{
				pthread_mutex_unlock(&philo->table->forks[left_fork]); // Release the left fork if right fork is not available
				pthread_mutex_unlock(&philo->table->forks[right_fork]); // Release the left fork if right fork is not available
			}
			pthread_mutex_unlock(&philo->table->global_mutex); // Unlock the global mutex if we couldn't take both forks
			usleep(100);
		}
	}
	else
	{
		while (1)
		{
			pthread_mutex_lock(&philo->table->global_mutex); // Lock the global mutex to check forks availability
			pthread_mutex_lock(&philo->table->forks[right_fork]);
			if (pthread_mutex_lock(&philo->table->forks[left_fork]) == 0)
			{
				pthread_mutex_unlock(&philo->table->global_mutex); // Unlock the global mutex as we have taken both forks
				if (philo->table->loop_end == 0)
					print_action(philo->id, "has taken a fork", philo->table->start_time);
				if (philo->table->loop_end == 0)
					print_action(philo->id, "has taken a fork", philo->table->start_time);
				return ; // Both forks taken, exit the function
			}
			else
			{
				pthread_mutex_unlock(&philo->table->forks[right_fork]); // Release the left fork if right fork is not available
				pthread_mutex_unlock(&philo->table->forks[left_fork]); // Release the left fork if right fork is not available
			}
			pthread_mutex_unlock(&philo->table->global_mutex); // Unlock the global mutex if we couldn't take both forks
			usleep(100);
		}
	}
} */

/* void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[left_fork]);
		if (philo->table->loop_end == 0)
			print_action(philo->id, "has taken a fork", philo->table->start_time);
		pthread_mutex_lock(&philo->table->forks[right_fork]);
		if (philo->table->loop_end == 0)
			print_action(philo->id, "has taken a fork", philo->table->start_time);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[right_fork]);
		if (philo->table->loop_end == 0)
			print_action(philo->id, "has taken a fork", philo->table->start_time);
		pthread_mutex_lock(&philo->table->forks[left_fork]);
		if (philo->table->loop_end == 0)
			print_action(philo->id, "has taken a fork", philo->table->start_time);
	}
} */

void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	pthread_mutex_lock(&philo->table->forks[left_fork]);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "has taken a fork", philo->table->start_time);
	pthread_mutex_lock(&philo->table->forks[right_fork]);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "has taken a fork", philo->table->start_time);
}

void	leave_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	pthread_mutex_unlock(&philo->table->forks[left_fork]);
	pthread_mutex_unlock(&philo->table->forks[right_fork]);
}
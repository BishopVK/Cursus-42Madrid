/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/11 12:16:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "is thinking", philo->table->start_time);
	pthread_mutex_unlock(&philo->table->end_mutex);
}

int	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "is eating", philo->table->start_time);
	pthread_mutex_unlock(&philo->table->end_mutex);
	//printf("DB: get_current_time() == %li\n", get_current_time());
	//printf("DB: philo->last_meal_time == %li\n", philo->last_meal_time);
	//printf("DB: get_current_time() - philo->last_meal_time == %li\n", get_current_time() - philo->last_meal_time);
	/* pthread_mutex_lock(&philo->table->end_mutex);
	if (get_current_time() - philo->last_meal_time < philo->table->time_to_eat)
	{
		usleep((get_current_time() - philo->last_meal_time) * 1000);  // DA ERROR
		philo->table->loop_end = true;
		return (pthread_mutex_unlock(&philo->table->end_mutex), 1);
	} */
	usleep(philo->table->time_to_eat * 1000);
	philo->meals_eaten++;
	pthread_mutex_lock(&philo->table->end_mutex);
	philo->last_meal_time = get_current_time(); // Need to protect whit mutex (data race detected)
	pthread_mutex_unlock(&philo->table->end_mutex);
	return (1);
}

void	sleep_philosopher(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "is sleeping", philo->table->start_time);
	pthread_mutex_unlock(&philo->table->end_mutex);
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

static t_bool	one_philo_case(t_philosopher *philo, int left_fork, int right_fork)
{
	if (left_fork == right_fork)
	{
		philo->table->loop_end = true;
		print_action(philo->id, "has taken a fork", philo->table->start_time);
		if (philo->table->time_to_die < philo->table->time_to_eat)
			usleep(philo->table->time_to_die * 1000);
		else
			usleep(philo->table->time_to_eat * 1000);
		//print_action(philo->id, "DB: Morí XD", philo->table->start_time);
		return (true);
	}
	return (false);
}

/* void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	pthread_mutex_lock(&philo->table->forks[left_fork]);
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "has taken a fork", philo->table->start_time);
	pthread_mutex_unlock(&philo->table->end_mutex);
	if (one_philo_case(philo, left_fork, right_fork) == true)
		return ;
	pthread_mutex_lock(&philo->table->forks[right_fork]);
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "has taken a fork", philo->table->start_time);
	pthread_mutex_unlock(&philo->table->end_mutex);
} */

void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;
	int	loop_ended;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	if (one_philo_case(philo, left_fork, right_fork) == true)
		return ;
	// Check loop_end only once to simplify mutex locking
	pthread_mutex_lock(&philo->table->end_mutex);
	loop_ended = philo->table->loop_end;
	pthread_mutex_unlock(&philo->table->end_mutex);

	if (loop_ended)
		return ;

	// Acquire forks in a fixed order based on the philosopher's ID
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[left_fork]);
		print_action(philo->id, "has taken a fork", philo->table->start_time);
		pthread_mutex_lock(&philo->table->forks[right_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[right_fork]);
		print_action(philo->id, "has taken a fork", philo->table->start_time);
		pthread_mutex_lock(&philo->table->forks[left_fork]);
	}
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
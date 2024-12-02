/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/08/05 18:28:40 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philosopher *philo)
{
	//if (philo->table->loop_end == 0)
		print_action(philo, "is thinking");
}

void	eat(t_philosopher *philo)
{
	// long	current;

	// current = get_current_time() - philo->table->start_time;

	long	current;
	long	time_since_last_meal;
	long	time_remaining;
	//if (philo->table->loop_end == 0)
		print_action(philo, "is eating");
	//usleep(philo->table->time_to_eat * 1000);
	//if (current + (philo->table->time_to_die * 1000) - (philo->table->time_to_eat * 1000) > current + (philo->table->time_to_eat * 1000))
	/* if (philo->last_meal_time + (philo->table->time_to_die * 1000) - (philo->table->time_to_eat * 1000) > current + (philo->table->time_to_eat * 1000))
	{
		usleep(philo->table->time_to_eat * 1000);
		//custom_sleep(philo->table->time_to_eat * 1000, philo);
		philo->meals_eaten++;
		philo->last_meal_time = get_current_time();
	} */
	// printf("philo->table->time_to_eat = %i\n", philo->table->time_to_eat);
	// printf("current = %li\n", current);
	// printf("philo->table->time_to_die = %i\n", philo->table->time_to_die);
	// printf("philo->last_meal_time = %li\n", philo->last_meal_time - philo->table->start_time);
	/* if (philo->table->time_to_eat > (philo->table->time_to_die - current - philo->table->start_time))
	{
		printf("philo->table->time_to_die - current = %li\n", philo->table->time_to_die - current);
		usleep(philo->table->time_to_die - current);
	} */

	current = get_current_time() - philo->table->start_time;
	time_since_last_meal = (philo->last_meal_time - current - philo->table->start_time) * -1;
	time_remaining = philo->table->time_to_die - time_since_last_meal;
	
	/* printf("current == %li\n", current);
	printf("time_since_last_meal == %li\n", time_since_last_meal);
	printf("time_remaining == %li\n", current); */

	if (time_remaining < philo->table->time_to_eat)
	{
		printf("HOLAAA!!!\n");
		usleep(time_remaining * 1000);
	}
	else
	{
		usleep(philo->table->time_to_eat * 1000);
		//custom_sleep(philo->table->time_to_eat * 1000, philo);
		philo->meals_eaten++;
		philo->last_meal_time = get_current_time();
		//printf("philo->last_meal_time == %li\n", philo->last_meal_time);
	}
}

void	sleep_philosopher(t_philosopher *philo)
{
	//long	current;

	//current = get_current_time();
	//if (philo->table->loop_end == 0)
		print_action(philo, "is sleeping");
	//if (current + philo->table->time_to_die > current + philo->table->time_to_sleep)
	//if (philo->last_meal_time + (philo->table->time_to_die * 1000) - (philo->table->time_to_sleep * 1000) > current + (philo->table->time_to_sleep * 1000))
		usleep(philo->table->time_to_sleep * 1000);
	//custom_sleep(philo->table->time_to_sleep * 1000, philo);
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
	right_fork = (philo->id) % philo->table->nbr_philos; // Calcula el tenedor derecho correctamente

	pthread_mutex_lock(&philo->table->forks[left_fork]);
	{
		printf("He cogido el tenerdor nº %i\n", left_fork);
		print_action(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->table->forks[right_fork]);
	{
		printf("He cogido el tenerdor nº %i\n", right_fork);
		print_action(philo, "has taken a fork");
	}
}

///////////////////////////////
/* void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = (philo->id + 1) % philo->table->nbr_philos; // Calcula el tenedor derecho correctamente

	pthread_mutex_lock(&philo->table->forks[left_fork]);
		print_action(philo, "has taken a fork");
	if (end_of_routine(philo->table) == true)
	{
		pthread_mutex_unlock(&philo->table->forks[left_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->table->forks[right_fork]);
		print_action(philo, "has taken a fork");
	if (end_of_routine(philo->table) == true)
	{
		pthread_mutex_unlock(&philo->table->forks[left_fork]);
		pthread_mutex_unlock(&philo->table->forks[right_fork]);
		return ;
	}
} */

/* void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	pthread_mutex_lock(&philo->table->forks[left_fork]);
	//if (philo->table->loop_end == 0)
		print_action(philo, "has taken a fork");
	if (end_of_routine(philo->table) == true)
		{
			pthread_mutex_unlock(&philo->table->forks[left_fork]);
			return ;
		}
	pthread_mutex_lock(&philo->table->forks[right_fork]);
	//if (philo->table->loop_end == 0)
		print_action(philo, "has taken a fork");
} */

void	leave_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	pthread_mutex_unlock(&philo->table->forks[left_fork]);
	pthread_mutex_unlock(&philo->table->forks[right_fork]);
}
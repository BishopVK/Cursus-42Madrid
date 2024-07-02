/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/02 08:30:10 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philosopher *philo)
{
	print_action(philo->id, "is thinking", philo->table->start_time);
	//usleep(1000);
}

void	eat(t_philosopher *philo)
{
	print_action(philo->id, "is eating", philo->table->start_time);
	usleep(philo->table->time_to_eat * 1000);
	philo->meals_eaten++;
	philo->last_meal_time = get_current_time();
}

void	sleep_philosopher(t_philosopher *philo)
{
	print_action(philo->id, "is sleeping", philo->table->start_time);
	usleep(philo->table->time_to_sleep * 1000);
}

void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	pthread_mutex_lock(&philo->table->forks[left_fork]);
	print_action(philo->id, "has taken a fork", philo->table->start_time);
	pthread_mutex_lock(&philo->table->forks[right_fork]);
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
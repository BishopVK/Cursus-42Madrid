/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:59:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 11:06:38 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static t_bool	one_philo_case(t_philosopher *philo,
					int left_fork, int right_fork)
{
	if (left_fork == right_fork)
	{
		print_action(philo->id, "has taken a fork", philo->table);
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_lock(&philo->table->end_mutex);
		philo->table->im_die = true;
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "died", philo->table);
		return (true);
	}
	return (false);
}

void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;
	if (one_philo_case(philo, left_fork, right_fork) == true)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[left_fork]);
		print_action(philo->id, "has taken a fork", philo->table);
		pthread_mutex_lock(&philo->table->forks[right_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[right_fork]);
		print_action(philo->id, "has taken a fork", philo->table);
		pthread_mutex_lock(&philo->table->forks[left_fork]);
	}
	print_action(philo->id, "has taken a fork", philo->table);
}

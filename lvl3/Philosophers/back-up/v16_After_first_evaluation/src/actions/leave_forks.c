/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:00:11 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 11:00:21 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	leave_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;
	if (philo->table->nbr_philos != 1)
	{
		pthread_mutex_unlock(&philo->table->forks[left_fork]);
		pthread_mutex_unlock(&philo->table->forks[right_fork]);
	}
}

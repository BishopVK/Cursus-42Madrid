/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:49:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 16:05:44 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	think(t_philosopher *philo)
{
	/* long	t_eat;
	long	t_sleep;
	long	t_think; */

	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == false)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is thinking", philo->table);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		return ;
	}
	if (philo->table->nbr_philos % 2 == 0)
		return ;
	/* t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.1); */
	ft_usleep(1);
}

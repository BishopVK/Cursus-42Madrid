/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:49:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 20:21:29 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	think(t_philosopher *philo)
{
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
	ft_usleep(1);
}

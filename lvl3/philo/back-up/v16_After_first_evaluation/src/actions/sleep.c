/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:59:11 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 11:58:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	sleep_philo(t_philosopher *philo, int t_sleep)
{
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == false)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is sleeping", philo->table);
	}
	else
		pthread_mutex_unlock(&philo->table->end_mutex);
	while (t_sleep <= philo->table->time_to_sleep)
	{
		pthread_mutex_lock(&philo->table->end_mutex);
		if (philo->table->loop_end == true)
		{
			pthread_mutex_unlock(&philo->table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->end_mutex);
		if (1 > philo->table->time_to_sleep - t_sleep)
			ft_usleep(philo->table->time_to_sleep - t_sleep);
		else
			ft_usleep(1);
		t_sleep += 1;
	}
}

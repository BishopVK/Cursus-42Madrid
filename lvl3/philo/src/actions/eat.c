/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:54:09 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 20:20:59 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	eat_sleep_loop(t_philosopher *philo)
{
	int	t_eat;

	t_eat = 0;
	while (t_eat <= philo->table->time_to_eat)
	{
		pthread_mutex_lock(&philo->table->end_mutex);
		if (philo->table->loop_end == true)
		{
			pthread_mutex_unlock(&philo->table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->end_mutex);
		if (1 > philo->table->time_to_eat - t_eat)
			ft_usleep(philo->table->time_to_eat - t_eat);
		else
			ft_usleep(1);
		t_eat += 1;
	}
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == false)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is eating", philo->table);
		pthread_mutex_lock(&philo->table->global_mutex);
		philo->table->total_meals++;
		philo->death_date = (get_current_time() - philo->last_meal_time)
			+ philo->table->time_to_die;
		philo->last_meal_time = get_current_time();
		pthread_mutex_unlock(&philo->table->global_mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		return ;
	}
	eat_sleep_loop(philo);
}

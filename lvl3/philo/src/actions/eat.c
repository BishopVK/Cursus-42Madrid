/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:54:09 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 19:08:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/* static int	insufficient_eat_time(t_philosopher *philo)
{
	long	remaining_life_time;

	remaining_life_time = philo->table->time_to_die
		- (get_current_time() - philo->last_meal_time);
	if (remaining_life_time < philo->table->time_to_eat)
	{
		ft_usleep(remaining_life_time);
		pthread_mutex_lock(&philo->table->end_mutex);
		philo->table->im_die = true;
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "died", philo->table);
		return (1);
	}
	return (0);
} */

void	eat_sleep_loop(t_philosopher *philo)
{
	int	t_eat;

	t_eat = 0;
	while (t_eat <= philo->table->time_to_eat)
	{
		pthread_mutex_lock(&philo->table->end_mutex);
		//if (philo->table->loop_end == true || t_eat >= philo->death_date - philo->last_meal_time)
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
	//printf("DB: philo[%i] death_date => %li\n", philo->id, philo->death_date);
	//printf("DB: get_current_time() => %li\n", get_current_time());
	//printf("DB: philo->last_meal_time => %li\n", philo->last_meal_time);
	//printf("DB: get_current_time() - philo->last_meal_time => %li\n", get_current_time() - philo->last_meal_time);
	if (get_current_time() - philo->last_meal_time > philo->death_date)
	{
		/* if (philo->table->time_to_eat > philo->table->time_to_die)
			ft_usleep(philo->table->time_to_eat - philo->table->time_to_die); */
		pthread_mutex_lock(&philo->table->end_mutex);
		philo->table->im_die = true;
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "died", philo->table);
		return ;
	}
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == false)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is eating", philo->table);
		pthread_mutex_lock(&philo->table->global_mutex);
		philo->table->total_meals++;
		philo->last_meal_time = get_current_time();
		philo->death_date = (get_current_time() - philo->last_meal_time) + philo->table->time_to_die;
		printf("DB: philo[%i] death_date => %li\n", philo->id, philo->death_date);
		pthread_mutex_unlock(&philo->table->global_mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		return ;
	}
	/* if (insufficient_eat_time(philo) == 1)
		return ; */
	eat_sleep_loop(philo);
	/* pthread_mutex_lock(&philo->table->global_mutex);
	philo->death_date = (get_current_time() - philo->last_meal_time) + philo->table->time_to_die;
	printf("DB: philo[%i] death_date => %li\n", philo->id, philo->death_date);
	//philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->table->global_mutex) */;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:11:43 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 21:17:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	end_of_routine(t_table *table)
{
	int	nbr_meals;

	pthread_mutex_lock(&table->end_mutex);
	if (table->loop_end)
	{
		pthread_mutex_unlock(&table->end_mutex);
		if (table->nbr_philos == 1)
			print_action(1, "died", table);
		return (true);
	}
	pthread_mutex_unlock(&table->end_mutex);
	pthread_mutex_lock(&table->global_mutex);
	nbr_meals = table->total_meals;
	pthread_mutex_unlock(&table->global_mutex);
	if (nbr_meals == (table->nbr_philos * table->nbr_must_eat))
	{
		pthread_mutex_lock(&table->end_mutex);
		table->im_die = true;
		pthread_mutex_unlock(&table->end_mutex);
		return (true);
	}
	return (0);
}

static void	philo_routine_loop(t_philosopher *philo)
{
	while (end_of_routine(philo->table) == false)
	{
		if (end_of_routine(philo->table) == true)
			break ;
		take_forks(philo);
		if (end_of_routine(philo->table) == true)
		{
			leave_forks(philo);
			break ;
		}
		eat(philo);
		if (end_of_routine(philo->table) == true)
		{
			leave_forks(philo);
			break ;
		}
		leave_forks(philo);
		if (end_of_routine(philo->table) == true)
			break ;
		sleep_philo(philo, 0);
		if (end_of_routine(philo->table) == true)
			break ;
		think(philo);
	}
	return ;
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->even_delay);
	if (philo->table->nbr_philos == 3 && philo->id == 3)
		ft_usleep(philo->table->even_delay);
	philo_routine_loop(philo);
	return (NULL);
}

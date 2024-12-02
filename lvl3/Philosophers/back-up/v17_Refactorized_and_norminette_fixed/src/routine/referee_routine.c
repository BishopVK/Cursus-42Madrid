/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   referee_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:12:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 21:12:14 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	detect_if_someone_dies(t_table *table)
{
	int	someone_dies;

	pthread_mutex_lock(&table->end_mutex);
	someone_dies = table->im_die;
	pthread_mutex_unlock(&table->end_mutex);
	if (someone_dies == true)
	{
		ft_usleep(1);
		pthread_mutex_lock(&table->end_mutex);
		table->loop_end = true;
		pthread_mutex_unlock(&table->end_mutex);
		return (ERR);
	}
	return (OK);
}

static int	detect_death_date(t_table *table, int i)
{
	long	time_restant;

	pthread_mutex_lock(&table->global_mutex);
	time_restant = table->philos[i].death_date;
	if (get_current_time() - table->philos[i].last_meal_time > time_restant)
	{
		pthread_mutex_unlock(&table->global_mutex);
		print_action(table->philos[i].id, "died", table);
		pthread_mutex_lock(&table->end_mutex);
		table->loop_end = true;
		pthread_mutex_unlock(&table->end_mutex);
		return (ERR);
	}
	pthread_mutex_unlock(&table->global_mutex);
	return (OK);
}

void	*referee_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		while (i < table->nbr_philos)
		{
			if (detect_if_someone_dies(table) == ERR)
				return (NULL);
			if (detect_death_date(table, i) == ERR)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

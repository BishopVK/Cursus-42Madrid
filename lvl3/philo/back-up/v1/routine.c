/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/01 21:45:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int id, char *action)
{
	printf("%ld: %d %s\n", get_current_time(), id, action);
}

static int	end_of_routine(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		if (get_current_time() - table->philos[i].last_meal_time > table->time_to_die)
		{
			print_action(table->philos[i].id, "died");
			return (1);
		}
		if (table->nbr_must_eat != -1 && table->philos[i].meals_eaten < table->nbr_must_eat)
			return (0);
		i++;
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (end_of_routine(philo->table) == 0)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		leave_forks(philo);
		sleep_philosopher(philo);
	}
	return (NULL);
}

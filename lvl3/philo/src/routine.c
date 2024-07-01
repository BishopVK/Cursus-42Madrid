/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/01 19:52:48 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int id, char *action)
{
	printf("%li: %i %s\n", get_current_time(), id, action);
}

void	*philo_routine(void *arg)
{
	t_philosopher *philo;

	philo = (t_philosopher *)arg;
	think(philo);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/01 19:45:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philosopher *philo)
{
	print_action(philo->id, "is thinking");
	usleep(1000);
}

void	eat(t_philosopher *philo)
{
	print_action(philo->id, "is eating");
	usleep(philo->table->time_to_eat * 1000);
	philo->meals_eaten++;
	philo->last_meal_time = get_current_time();
}
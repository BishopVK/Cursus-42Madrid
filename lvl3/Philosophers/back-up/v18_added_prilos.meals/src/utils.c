/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:54 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/21 12:07:07 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_current_time(void)
{
	struct timeval	current;
	long			current_miliseconds;

	gettimeofday(&current, NULL);
	current_miliseconds = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (current_miliseconds);
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < time)
		usleep(200);
}

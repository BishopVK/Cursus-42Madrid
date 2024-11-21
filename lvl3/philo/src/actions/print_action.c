/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:09:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/21 09:15:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_action(int id, char *action, t_table *table)
{
	int			loop_ended;
	static int	nbr_dies;

	pthread_mutex_lock(&table->end_mutex);
	loop_ended = table->loop_end;
	pthread_mutex_unlock(&table->end_mutex);
	if (!loop_ended)
	{
		pthread_mutex_lock(&table->print_mutex);
		if (nbr_dies == 0)
			printf("%ld %d %s\n", get_current_time() - table->start_time,
				id, action);
		if (ft_strcmp(action, "died") == 0)
			nbr_dies++;
		pthread_mutex_unlock(&table->print_mutex);
	}
}

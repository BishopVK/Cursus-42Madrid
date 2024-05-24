/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:46:25 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/24 14:20:16 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	detect_player(char *buffer, t_map_array *map_array, int map_lines)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
		{
			map_array->startX = i;
			map_array->startY = map_lines;
			break ;
		}
		i++;
	}
}

/* void	flood_fill(t_map_array	*map)
{
	detect_player(&map);
} */
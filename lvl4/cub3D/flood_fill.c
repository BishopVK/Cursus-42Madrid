/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:46:25 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/28 23:16:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	detect_player_and_exit(char *buffer, t_map_array *map_array,
			int map_lines)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
		{
			map_array->start_x = i;
			map_array->start_y = map_lines;
			break ;
		}
		i++;
	}
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'E')
		{
			map_array->exit_x = i;
			map_array->exit_y = map_lines;
			break ;
		}
		i++;
	}
}

void	verify_flood_fill_result(t_map_chars *copy_chars,
			t_map_array *map_array)
{
	if (copy_chars->player != 0 || copy_chars->exit != 0
		|| copy_chars->collectible != 0)
	{
		dprintf(2, "Error\n> Map imposible to solve\n");
		free_array(map_array);
		exit (EXIT_FAILURE);
	}
}

void	flood_fill(t_map_chars *copy_chars, t_map_array *copy_array,
			int x, int y)
{
	if (x < 1 || x >= copy_array->height || y < 1 || y >= copy_array->width
		|| copy_array->map[x][y] == '1' || copy_array->map[x][y] == 'V')
		return ;
	if (copy_array->map[x][y] == 'P')
		copy_chars->player--;
	else if (copy_array->map[x][y] == 'E')
		copy_chars->exit--;
	else if (copy_array->map[x][y] == 'C')
		copy_chars->collectible--;
	copy_array->map[x][y] = 'V';
	flood_fill(copy_chars, copy_array, x + 1, y);
	flood_fill(copy_chars, copy_array, x - 1, y);
	flood_fill(copy_chars, copy_array, x, y + 1);
	flood_fill(copy_chars, copy_array, x, y - 1);
} */

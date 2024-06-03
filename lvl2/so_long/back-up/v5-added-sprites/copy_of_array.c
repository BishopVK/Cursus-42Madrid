/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_of_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:53:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/31 09:38:08 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_copy_map_chars(t_map_chars *map_chars, t_map_chars *copy_chars)
{
	copy_chars->collectible = map_chars->collectible;
	copy_chars->empty = map_chars->empty;
	copy_chars->exit = map_chars->exit;
	copy_chars->player = map_chars->player;
	copy_chars->wall = map_chars->wall;
}

void	initialize_copy_array(t_map_array *map_array, t_map_array *copy_array)
{
	copy_array->height = map_array->height;
	copy_array->width = map_array->width;
	copy_array->start_x = map_array->start_x;
	copy_array->start_y = map_array->start_y;
}

void	create_array_copy(t_map_array *map_array, t_map_array *copy_array)
{
	int		i;
	int		j;

	initialize_copy_array(map_array, copy_array);
	copy_array->map = (char **)malloc((copy_array->height + 1) * sizeof(char *));
	i = 0;
	while (i < copy_array->height)
	{
		copy_array->map[i] = (char *)malloc(copy_array->width + 1);
		if (!copy_array->map[i])
		{
			j = 0;
			while (j < i)
				free(copy_array->map[j++]);
			free(copy_array->map);
			ft_dprintf(2, "Failed to allocate memory for buffer\n");
			exit (EXIT_FAILURE);
		}
		ft_strcpy(copy_array->map[i], map_array->map[i]);
		i++;
	}
	copy_array->map[i] = NULL;
}

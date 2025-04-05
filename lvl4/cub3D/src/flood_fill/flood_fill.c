/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:00:33 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/05 02:12:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	count_pieces(t_map *map_s, char **copy)
{
	int	i;
	int	j;
	int	count_v;

	i = 0;
	count_v = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'V')
				count_v++;
			j++;
		}
		i++;
	}
	if (count_v != map_s->total_map_chars)
	{
		free_double_pointer(copy);
		exit_map_error(map_s, "Maps with more than one piece are not allowed", -1);
		exit (EXIT_FAILURE);
	}
	else // DB
		printf("MAPA DE UNA SÓLA PIEZA!! PUEDES CONTINUAR\n"); // DB
}

void	flood_fill_v(t_map *map_s, char **copy, int x, int y)
{
	if (x < map_s->corner_y || x > map_s->map_height
		|| y < 0 || y >= (int)ft_strlen(map_s->map[x])
		|| copy[x][y] == ' ' || copy[x][y] == '\n' || copy[x][y] == 'V')
		return ;
	/* else
		printf("\n-- HOLA --\n"); // DB */
	copy[x][y] = 'V';
	
	flood_fill_v(map_s, copy, x + 1, y);
	flood_fill_v(map_s, copy, x - 1, y);
	flood_fill_v(map_s, copy, x, y + 1);
	flood_fill_v(map_s, copy, x, y - 1);
}

void	init_flood_fill(t_map *map_s)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc((map_s->map_height + 1) * sizeof(char *));
	while (i < map_s->map_height)
	{
		copy[i] = (char *)malloc(ft_strlen(map_s->map[i]) + 1);
		if (!copy[i])
		{
			free_double_pointer(copy);
			exit_map_error(map_s, "Error allocating memory for copy", -1);
			exit (EXIT_FAILURE);
		}
		ft_strcpy(copy[i], map_s->map[i]);
		i++;
	}
	copy[i] = NULL;
	printf("\n-- COPY --\n"); // DB
	print_map(copy); // DB
	flood_fill_v(map_s, copy, map_s->corner_y, map_s->corner_x);
	printf("\n-- AFTER FLOOD FILL --\n"); // DB
	print_map(copy); // DB
	count_pieces(map_s, copy);
	free_double_pointer(copy);
}

/* void	flood_fill(t_map_chars *copy_chars, t_map *copy_array,
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
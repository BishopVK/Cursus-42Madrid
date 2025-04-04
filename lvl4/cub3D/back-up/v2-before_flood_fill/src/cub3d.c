/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:39:00 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/02 16:17:27 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	initialize_structs(t_map *map_s, t_map_chars *map_chars,
	t_rgb *floor_rgb, t_rgb *ceiling_rgb)
{
	ft_memset(map_s, 0, sizeof(t_map));
	ft_memset(map_chars, 0, sizeof(t_map_chars));
	ft_memset(floor_rgb, 0, sizeof(t_rgb));
	ft_memset(ceiling_rgb, 0, sizeof(t_rgb));

	map_s->chars = map_chars;  // Apuntar a la memoria de map_chars
	map_s->floor = floor_rgb;
	map_s->ceiling = ceiling_rgb;
}

int	main(int argc, char *argv[])
{
	t_map	map_s;
	t_map_chars	map_chars;
	t_rgb		floor_rgb;
	t_rgb		ceiling_rgb;

	initialize_structs(&map_s, &map_chars, &floor_rgb, &ceiling_rgb);
	if (argc != 2)
	{
		ft_dprintf(2, "Error\n> Correct use: %s map.cub\n", argv[0]);
		return (EXIT_FAILURE);
	}
	check_arg_extension(argv[1]);
	read_map(argv[1], &map_s);
	free_elements(&map_s);
	free_double_pointer(map_s.map);
	/*read_to_create_array(argv[1], &map_array);
	create_copy_map_chars(&map_chars, &copy_chars);
	create_array_copy(&map_array, &copy_array);
	flood_fill(&copy_chars, &copy_array, copy_array.start_y,
		copy_array.start_x);
	free_array(&copy_array);
	verify_flood_fill_result(&copy_chars, &map_array);
	initialize_game(&map_chars, &map_array); */
	return (EXIT_SUCCESS);
}

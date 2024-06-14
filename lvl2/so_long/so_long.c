/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:39:00 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/14 11:48:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map_chars	map_chars;
	t_map_array	map_array;
	t_map_chars	copy_chars;
	t_map_array	copy_array;

	ft_memset(&map_chars, 0, sizeof(t_map_chars));
	ft_memset(&map_array, 0, sizeof(t_map_array));
	ft_memset(&copy_array, 0, sizeof(t_map_array));
	if (argc != 2)
	{
		ft_dprintf(2, "Error\n> Correct use: %s map.ber\n", argv[0]);
		return (-1);
	}
	check_arg_extension(argv[1]);
	read_map(argv[1], &map_chars, &map_array);
	read_to_create_array(argv[1], &map_array);
	create_copy_map_chars(&map_chars, &copy_chars);
	create_array_copy(&map_array, &copy_array);
	flood_fill(&copy_chars, &copy_array, copy_array.start_y,
		copy_array.start_x);
	free_array(&copy_array);
	verify_flood_fill_result(&copy_chars, &map_array);
	initialize_game(&map_chars, &map_array);
	return (EXIT_SUCCESS);
}

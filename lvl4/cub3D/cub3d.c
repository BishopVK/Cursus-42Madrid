/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:39:00 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/29 22:23:07 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Error\n> Correct use: %s map.cub\n", argv[0]);
		return (EXIT_FAILURE);
	}
	check_arg_extension(argv[1]);
	read_map(argv[1], &map_chars, &map_array);
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

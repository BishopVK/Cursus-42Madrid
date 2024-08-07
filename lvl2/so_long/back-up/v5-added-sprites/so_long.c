/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:39:00 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/03 11:15:27 by danjimen         ###   ########.fr       */
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
		ft_dprintf(2, "Correct use: %s map.ber\n", argv[0]);
		return (-1);
	}
	check_arg_extension(argv[1]);
	read_map(argv[1], &map_chars, &map_array);
	ft_printf("map_array.width ==> %i\n", map_array.width);
	ft_printf("map_array.height ==> %i\n", map_array.height);
	read_to_create_array(argv[1], &map_array);
	ft_printf("\n>>>> ¡¡THE MAP IS CORRECT!! <<<<\n\n");
	ft_printf("map_array:\n");
	display_array(&map_array);
	ft_printf("Player = (%i,%i)\n", map_array.start_x, map_array.start_y);

	ft_printf("-----------\n");
	create_copy_map_chars(&map_chars, &copy_chars);
	create_array_copy(&map_array, &copy_array);
	ft_printf("copy:\n");
	display_array(&copy_array);
	//ft_printf("copy_array->map[x][y] ==> %c\n", copy_array.map[3][1]);
	ft_printf("Player_copy = (%i,%i)\n", copy_array.start_x, copy_array.start_y);


	ft_printf("copy_chars.collectible = %i\n", copy_chars.collectible);
	ft_printf("copy_chars.player = %i\n", copy_chars.player);
	ft_printf("copy_chars.exit = %i\n", copy_chars.exit);

	ft_printf(">>player X = %i\n", copy_array.start_x);
	ft_printf(">>player Y = %i\n", copy_array.start_y);
	flood_fill(&copy_chars, &copy_array, copy_array.start_y, copy_array.start_x);
	ft_printf("flood_fill:\n");
	display_array(&copy_array);
	ft_printf("copy_chars.collectible = %i\n", copy_chars.collectible);
	ft_printf("copy_chars.player = %i\n", copy_chars.player);
	ft_printf("copy_chars.exit = %i\n", copy_chars.exit);

	//Initialize minilibx
	//initialize_game(&map_chars, &map_array);

	free_array(&map_array);
	free_array(&copy_array);
	return (EXIT_SUCCESS);
}

/* map_chars.empty = 0;
map_chars.wall = 0;
map_chars.collectible = 0;
map_chars.exit = 0;
map_chars.player = 0; */

// cc -I /usr/local/include main.c -L /usr/local/lib/ -lmlx
// -framework OpenGL -framework AppKit
/* int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
	(void)win_ptr;
	return 0;
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:39:00 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/22 12:13:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map_chars	map_chars;
	t_map_array	map_array;

	ft_memset(&map_chars, 0, sizeof(t_map_chars));
	ft_memset(&map_array, 0, sizeof(t_map_array));
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
	ft_printf("\n¡¡THE MAP IS CORRECT!!\n");
	
	return (0);
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

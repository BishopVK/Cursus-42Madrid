/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:39:00 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/16 13:39:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_dprintf(2, "Correct use: %s map.ber\n", argv[0]);
		return (-1);
	}
	check_arg_extension(argv[1]);
	read_map(argv[1]);
	return (0);
}

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

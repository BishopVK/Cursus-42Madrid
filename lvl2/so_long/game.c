/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:59:27 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/27 21:23:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_map_chars	*map_chars, t_map_array	*map_array)
{
	void	*mlx;
	void	*mlx_win;

	(void)map_chars;
	(void)map_array;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "danjimen's game!");
	mlx_loop(mlx);
	(void)mlx_win;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:59:27 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/31 14:09:59 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

void	initialize_game(t_map_chars	*map_chars, t_map_array	*map_array)
{
	t_data	data;

	(void)map_array;
	(void)map_chars;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit (1);
	mlx_get_screen_size(data.mlx_ptr, &data.screen_width, &data.screen_height);
	ft_printf("Screen: %dx%d\n", data.screen_width, data.screen_height);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "danjimen's game!");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		exit (1);
	}

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
}
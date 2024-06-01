/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:59:27 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/01 23:17:01 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

void	get_images_and_paths(t_data *data)
{
	data->img->player_path = "./sprites/xpm/game/player/player_idle_1.xpm";
	data->img->collec_path = "./sprites/xpm/game/collectible/M_Idle.xpm";
	data->img->wall_path = "./sprites/xpm/game/water/Water.xpm";
	data->img->back_path = "./sprites/xpm/game/background/middle.xpm";
	data->img->exit_path = "./sprites/xpm/game/exit/stairs_4.xpm";
	data->img->enemy_path = "./sprites/xpm/game/sheep/sheep_idle_1.xpm";
	data->img->img_px = 64;
	data->img->player = mlx_xpm_file_to_image(data->mlx_ptr,
		data->img->player_path, &data->img->img_px, &data->img->img_px);
	data->img->collec = mlx_xpm_file_to_image(data->mlx_ptr,
		data->img->collec_path, &data->img->img_px, &data->img->img_px);
	data->img->wall = mlx_xpm_file_to_image(data->mlx_ptr,
		data->img->wall_path, &data->img->img_px, &data->img->img_px);
	data->img->back = mlx_xpm_file_to_image(data->mlx_ptr,
		data->img->back_path, &data->img->img_px, &data->img->img_px);
	data->img->exit = mlx_xpm_file_to_image(data->mlx_ptr,
		data->img->exit_path, &data->img->img_px, &data->img->img_px);
	data->img->enemy = mlx_xpm_file_to_image(data->mlx_ptr,
		data->img->enemy_path, &data->img->img_px, &data->img->img_px);
}

void	put_images(t_data *data, t_map_array *map_array)
{
	int	i;
	int	j;

	data->img = (t_img *)malloc(sizeof(t_img));
	get_images_and_paths(data);
	i = 0;
	while (map_array->map[i])
	{
		j = 0;
		while (map_array->map[i][j])
		{
			if (map_array->map[i][j] == '0' && map_array->map[i + 1][j] == '1' && map_array->map[i - 1][j] == '1' && map_array->map[i][j + 1] == '1' && map_array->map[i][j - 1] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->enemy, (j * 64), (i * 64));
			else if (map_array->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->player, (j * 64), (i * 64));
			else if (map_array->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->collec, (j * 64), (i * 64));
			else if (map_array->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->wall, (j * 64), (i * 64));
			else if (map_array->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back, (j * 64), (i * 64));
			else if (map_array->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, (j * 64), (i * 64));
			else if (map_array->map[i][j] == 'K')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->enemy, (j * 64), (i * 64));
			j++;
		}
		i++;
	}

	/*
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->player, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->collec, 64, 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->wall, 128, 128);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back, 192, 192);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, 256, 256);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->enemy, 320, 320);
	*/
}

void	initialize_game(t_map_chars	*map_chars, t_map_array	*map_array)
{
	t_data	data;

	(void)map_chars;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit (1);
	//img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);
	mlx_get_screen_size(data.mlx_ptr, &data.screen_width, &data.screen_height);
	ft_printf("Screen: %dx%d\n", data.screen_width, data.screen_height);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 832, 320, "danjimen's game!");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		exit (1);
	}

	put_images(&data, map_array);
	// Put the image to the window
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 0, 0);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);

	// AT END
	free(data.img);
}
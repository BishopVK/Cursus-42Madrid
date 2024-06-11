/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:59:27 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/11 22:39:37 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_data *data)
{
	if (data->img)
	{
		if (data->img->player)
			mlx_destroy_image(data->mlx_ptr, data->img->player);
		if (data->img->collec)
			mlx_destroy_image(data->mlx_ptr, data->img->collec);
		if (data->img->wall)
			mlx_destroy_image(data->mlx_ptr, data->img->wall);
		if (data->img->wall_border)
			mlx_destroy_image(data->mlx_ptr, data->img->wall_border);
		if (data->img->back)
			mlx_destroy_image(data->mlx_ptr, data->img->back);
		if (data->img->exit)
			mlx_destroy_image(data->mlx_ptr, data->img->exit);
		if (data->img->enemy)
			mlx_destroy_image(data->mlx_ptr, data->img->enemy);
		free(data->img);
		data->img = NULL;
	}
}

void	free_mlx_resources(t_data *data)
{
	if (data->img != NULL)
	{
		clean_up(data);
	}
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_loop_end(data->mlx_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}

int	on_destroy(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_mlx_resources(data);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == UP_KEY || keysym == W_KEY)
	{
		ft_printf("Moved Up\n");
	}
	else if (keysym == DOWN_KEY || keysym == S_KEY)
		ft_printf("Moved Down\n");
	else if (keysym == RIGHT_KEY || keysym == D_KEY)
		ft_printf("Moved Right\n");
	else if (keysym == LEFT_KEY || keysym == A_KEY)
		ft_printf("Moved Left\n");
	else if (keysym == ESC_KEY)
	{
		ft_printf("Pressed ESC key\n");
		on_destroy(data);
	}
	else
		ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

void	*new_file_img(char *path, t_data *data, t_map_array *map_array)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
		path, &data->img->img_px, &data->img->img_px);
	if (img == 0)
	{
		free_array(map_array);
		free_mlx_resources(data);
		ft_dprintf(2, "Error\n> Creating img whit %s\n", path);
		exit (EXIT_FAILURE);
	}
	return (img);
}

void	get_images_and_paths(t_data *data, t_map_array *map_array)
{
	data->img->player_path = "./sprites/xpm/TinyRanch/Player/char_front_idle_1.xpm";
	data->img->collec_path = "./sprites/xpm/TinyRanch/Item/tomato.xpm";
	data->img->wall_path = "./sprites/xpm/TinyRanch/Tileset/water_2.xpm";
	data->img->wall_border_path = "./sprites/xpm/TinyRanch/Tileset/water_border_1.xpm";
	data->img->back_path = "./sprites/xpm/TinyRanch/Tileset/background.xpm";
	data->img->exit_path = "./sprites/xpm/TinyRanch/Exit/stairs_4.xpm";
	data->img->enemy_path = "./sprites/xpm/TinyRanch/Enemy/sheep_idle_1.xpm";
	data->img->img_px = 64;

	data->img->player = new_file_img(data->img->player_path, data, map_array);
	data->img->collec = new_file_img(data->img->collec_path, data, map_array);
	data->img->wall = new_file_img(data->img->wall_path, data, map_array);
	data->img->wall_border = new_file_img(data->img->wall_border_path, data, map_array);
	data->img->back = new_file_img(data->img->back_path, data, map_array);
	data->img->exit = new_file_img(data->img->exit_path, data, map_array);
	data->img->enemy = new_file_img(data->img->enemy_path, data, map_array);

	/* data->img->player = mlx_xpm_file_to_image(data->mlx_ptr,
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
		data->img->enemy_path, &data->img->img_px, &data->img->img_px); */
}

void	put_images(t_data *data, t_map_array *map_array)
{
	int	x;
	int	y;

	data->img = (t_img *)malloc(sizeof(t_img));
	ft_memset(data->img, 0, sizeof(t_img));
	get_images_and_paths(data, map_array);
	y = 0;
	while (map_array->map[y])
	{
		x = 0;
		while (map_array->map[y][x])
		{
			if (y > 0 && map_array->map[y][x] == '1' && map_array->map[y - 1][x] != '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->wall_border, (x * 64), (y * 64));
			else if (map_array->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->player, (x * 64), (y * 64));
			else if (map_array->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->collec, (x * 64), (y * 64));
			else if (map_array->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->wall, (x * 64), (y * 64));
			else if (map_array->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back, (x * 64), (y * 64));
			else if (map_array->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, (x * 64), (y * 64));
			else if (map_array->map[y][x] == 'K')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->enemy, (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

void	verify_map_size(t_map_array *map_array, t_data *data)
{
	if (map_array->width * 64 > data->screen_width
		|| map_array->height * 64 > data->screen_height)
	{
		free_array(map_array);
		free_mlx_resources(data);
		ft_dprintf(2, "Error\n> The map is higger than screen resolution\n");
		exit (EXIT_FAILURE);
	}
}

void	initialize_game(t_map_chars *map_chars, t_map_array *map_array)
{
	t_data	data;

	(void)map_chars;
	ft_printf("map_array->width ==> %i\n", map_array->width);
	ft_printf("map_array->height ==> %i\n", map_array->height);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit (1);
	//img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);
	mlx_get_screen_size(data.mlx_ptr, &data.screen_width, &data.screen_height);
	ft_printf("Screen: %dx%d\n", data.screen_width, data.screen_height);
	data.img = NULL;
	data.win_ptr = mlx_new_window(data.mlx_ptr, map_array->width * 64, map_array->height * 64, "danjimen's game!");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		exit (1);
	}
	
	// Verify if map fits in the screen resolution
	verify_map_size(map_array, &data);

	// Put the image to the window
	put_images(&data, map_array);

	// Put text to the window
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 25, 0x000000, "Hola!");

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Use when map_array is not necesary
	free_array(map_array);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);

	// AT END: Clean all
	free_mlx_resources(&data);
}

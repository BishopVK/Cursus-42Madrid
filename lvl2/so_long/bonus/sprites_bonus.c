/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:04:48 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/14 14:04:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*new_file_img(char *path, t_data *data)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
		path, &data->img->img_px, &data->img->img_px);
	if (img == 0)
	{
		ft_dprintf(2, "Error\n> Creating img whit %s\n", path);
		on_destroy(data);
		exit (EXIT_FAILURE);
	}
	return (img);
}

void	get_images_and_paths(t_data *data)
{
	data->img->player_path[0] = "./sprites/xpm/TinyRanch/Player/char_front_idle_1.xpm";
	data->img->player_path[1] = "./sprites/xpm/TinyRanch/Player/char_back_idle_1.xpm";
	data->img->player_path[2] = "./sprites/xpm/TinyRanch/Player/char_left_idle_1.xpm";
	data->img->player_path[3] = "./sprites/xpm/TinyRanch/Player/char_right_idle_1.xpm";
	data->img->collec_path = "./sprites/xpm/TinyRanch/Item/tomato.xpm";
	data->img->wall_path = "./sprites/xpm/TinyRanch/Tileset/water_2.xpm";
	data->img->wall_border_path = "./sprites/xpm/TinyRanch/Tileset/water_border_1.xpm";
	data->img->back_path = "./sprites/xpm/TinyRanch/Tileset/background.xpm";
	data->img->exit_path = "./sprites/xpm/TinyRanch/Exit/exit_4.xpm";
	data->img->enemy_path = "./sprites/xpm/TinyRanch/Enemy/sheep_idle_1.xpm";
	data->img->img_px = 64;

	data->img->player = new_file_img(data->img->player_path[0], data);
	data->img->collec = new_file_img(data->img->collec_path, data);
	data->img->wall = new_file_img(data->img->wall_path, data);
	data->img->wall_border = new_file_img(data->img->wall_border_path, data);
	data->img->back = new_file_img(data->img->back_path, data);
	data->img->exit = new_file_img(data->img->exit_path, data);
	data->img->enemy = new_file_img(data->img->enemy_path, data);
}

void	put_images(t_data *data, t_map_array *map_array)
{
	int	x;
	int	y;

	data->img = (t_img *)malloc(sizeof(t_img));
	ft_memset(data->img, 0, sizeof(t_img));
	get_images_and_paths(data);
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
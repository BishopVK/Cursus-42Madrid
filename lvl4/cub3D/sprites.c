/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:04:47 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/28 23:17:59 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	put_images_on_window(t_data *data, t_map_array *map_array,
			int *x, int *y)
{
	if (*y > 0 && map_array->map[*y][*x] == '1' &&
		map_array->map[*y - 1][*x] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->wall_border, (*x * 64), (*y * 64));
	else if (map_array->map[*y][*x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->player, (*x * 64), (*y * 64));
	else if (map_array->map[*y][*x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->collec, (*x * 64), (*y * 64));
	else if (map_array->map[*y][*x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->wall, (*x * 64), (*y * 64));
	else if (map_array->map[*y][*x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->back, (*x * 64), (*y * 64));
	else if (map_array->map[*y][*x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->exit, (*x * 64), (*y * 64));
	else if (map_array->map[*y][*x] == 'K')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->enemy, (*x * 64), (*y * 64));
}

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
	data->img->player_path = "./textures/xpm/Player/char_front_idle_1.xpm";
	data->img->collec_path = "./textures/xpm/Item/tomato.xpm";
	data->img->wall_path = "./textures/xpm/Tileset/water_2.xpm";
	data->img->wall_border_path = "./textures/xpm/Tileset/water_border_1.xpm";
	data->img->back_path = "./textures/xpm/Tileset/background.xpm";
	data->img->exit_path = "./textures/xpm/Exit/exit_0.xpm";
	data->img->exit_path_2 = "./textures/xpm/Exit/exit_4.xpm";
	data->img->enemy_path = "./textures/xpm/Enemy/sheep_idle_1.xpm";
	data->img->img_px = 64;
	data->img->player = new_file_img(data->img->player_path, data);
	data->img->collec = new_file_img(data->img->collec_path, data);
	data->img->wall = new_file_img(data->img->wall_path, data);
	data->img->wall_border = new_file_img(data->img->wall_border_path, data);
	data->img->back = new_file_img(data->img->back_path, data);
	data->img->exit = new_file_img(data->img->exit_path, data);
	data->img->exit_2 = new_file_img(data->img->exit_path_2, data);
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
			put_images_on_window(data, map_array, &x, &y);
			x++;
		}
		y++;
	}
} */

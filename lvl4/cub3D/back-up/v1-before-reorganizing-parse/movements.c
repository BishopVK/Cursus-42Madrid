/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:42:36 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/28 23:17:47 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static void	win_game(t_data *data, int new_x, int new_y)
{
	if (data->map_array->map[new_y][new_x] == 'E' &&
		data->map_array->chars->collectible == 0)
	{
		ft_printf("You win!\n");
		on_destroy(data);
	}
}

static void	update_win_sprites(t_data *data, int x, int y)
{
	data->map_array->moves++;
	if (y == data->map_array->exit_y && x == data->map_array->exit_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->exit, x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->back, x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = '0';
	}
	ft_printf("Counter: %i\n", data->map_array->moves);
	if (data->map_array->chars->collectible == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->exit_2, data->map_array->exit_x * data->img->img_px,
			data->map_array->exit_y * data->img->img_px);
	}
}

static void	move_resume(t_map_array *map_array, int *x, int *y, int dir)
{
	if (dir == UP_KEY)
		*y -= 1;
	if (dir == DOWN_KEY)
		*y += 1;
	if (dir == LEFT_KEY)
		*x -= 1;
	if (dir == RIGHT_KEY)
		*x += 1;
	if (map_array->map[*y][*x] == 'C')
	{
		map_array->map[*y][*x] = '0';
		map_array->chars->collectible--;
		ft_printf("Items remeaning: %i\n", map_array->chars->collectible);
	}
}

void	move_player(t_data *data, int dir)
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;

	x = data->map_array->start_x;
	y = data->map_array->start_y;
	new_x = x;
	new_y = y;
	move_resume(data->map_array, &new_x, &new_y, dir);
	if (new_x >= 0 && new_x < data->map_array->width
		&& new_y >= 0 && new_y < data->map_array->height
		&& data->map_array->map[new_y][new_x] != '1')
	{
		win_game(data, new_x, new_y);
		update_win_sprites(data, x, y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->player,
			new_x * data->img->img_px, new_y * data->img->img_px);
		data->map_array->map[new_y][new_x] = 'P';
		data->map_array->start_x = new_x;
		data->map_array->start_y = new_y;
	}
}
 */
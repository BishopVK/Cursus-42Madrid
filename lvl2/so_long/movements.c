/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:58:35 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/12 09:32:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_resume(t_map_array *map_array, int x, int y, int dir)
{
	if (dir == UP_KEY)
		y -= 1;
	if (dir == DOWN_KEY)
		y += 1;
	if (dir == LEFT_KEY)
		x -= 1;
	if (dir == RIGHT_KEY)
		x += 1;
	if (map_array->map[y][x] == 'E' && map_array->chars->collectible == 0)
		return (ft_win(map_array));
	if (map_array->map[y][x] == 'C')
	{
		map_array->map[y][x] = '0';
		map_array->chars->collectible--;
	}
}

void	move_up(t_data	*data)
{
	int	x;
	int	y;

	x = data->map_array->start_x;
	y = data->map_array->start_y;
	if (y > 0 && data->map_array->map[y - 1][x] != '1')
	{
		move_resume(data->map_array, x, y, UP_KEY);
		if (data->map_array->map[y - 1][x] == 'E' && (data->map_array->chars->collectible != 0 || data->map_array->chars->exit == 1))
			return ;
		data->map_array->moves++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back,
			x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = '0';
		y--;
		print_movements(data->map_array);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back,
			x * data->img->img_px, y * data->img->img_px);
		// Put player_back_idle
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->player,
			x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = 'P';
		data->map_array->start_x = x;
	}
}

void	move_left(t_data	*data)
{
	int	x;
	int	y;

	x = data->map_array->start_x;
	y = data->map_array->start_y;
	if (x > 0 && data->map_array->map[y][x - 1] != '1')
	{
		move_resume(data->map_array, x, y, LEFT_KEY);
		if (data->map_array->map[y][x - 1] == 'E' && (data->map_array->chars->collectible != 0 || data->map_array->chars->exit == 1))
			return ;
		data->map_array->moves++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back,
			x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = '0';
		x--;
		print_movements(data->map_array);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back,
			x * data->img->img_px, y * data->img->img_px);
		// Put player_left_idle
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->player,
			x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = 'P';
		data->map_array->start_y = y;
	}
}

void	move_down(t_data	*data)
{
	int	x;
	int	y;

	x = data->map_array->start_x;
	y = data->map_array->start_y;
	if (y < data->map_array->height && data->map_array->map[y + 1][x] != '1')
	{
		move_resume(data->map_array, x, y, DOWN_KEY);
		if (data->map_array->map[y + 1][x] == 'E' && (data->map_array->chars->collectible != 0 || data->map_array->chars->exit == 1))
			return ;
		data->map_array->moves++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back,
			x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = '0';
		y++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back,
			x * data->img->img_px, y * data->img->img_px);
		// Put player_front_idle
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->player,
			x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = 'P';
		print_movements(data->map_array);
		data->map_array->start_y = y;
	}
}

void	move_right(t_data	*data)
{
	int	x;
	int	y;

	x = data->map_array->start_x;
	y = data->map_array->start_y;
	if (x < data->map_array->width && data->map_array->map[y][x + 1] != '1')
	{
		move_resume(data->map_array, x, y, RIGHT_KEY);
		if (data->map_array->map[y][x + 1] == 'E' && (data->map_array->chars->collectible != 0 || data->map_array->chars->exit == 1))
			return ;
		data->map_array->moves++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back,
			x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = '0';
		x++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->back,
			x * data->img->img_px, y * data->img->img_px);
		// Put player_right_idle
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->player,
			x * data->img->img_px, y * data->img->img_px);
		data->map_array->map[y][x] = 'P';
		print_movements(data->map_array);
	}
	data->map_array->start_x = x;
}
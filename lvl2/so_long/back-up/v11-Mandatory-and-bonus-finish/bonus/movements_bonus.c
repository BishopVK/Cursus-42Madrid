/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:04:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/14 20:23:25 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_animation(t_data *data, int new_x, int new_y, int dir)
{
	if (dir == DOWN_KEY)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img->player[0],
			new_x * data->img->img_px, new_y * data->img->img_px);
	if (dir == UP_KEY)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img->player[1],
			new_x * data->img->img_px, new_y * data->img->img_px);
	if (dir == LEFT_KEY)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img->player[2],
			new_x * data->img->img_px, new_y * data->img->img_px);
	if (dir == RIGHT_KEY)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img->player[3],
			new_x * data->img->img_px, new_y * data->img->img_px);
}

static void	win_and_lose_game(t_data *data, int new_x, int new_y)
{
	if (data->map_array->map[new_y][new_x] == 'E' &&
		data->map_array->chars->collectible == 0)
	{
		ft_printf("You win!\n");
		on_destroy(data);
	}
	if (data->map_array->map[new_y][new_x] == 'K')
	{
		ft_printf("You lose!\n");
		on_destroy(data);
	}
}

static void	update_window_sprites(t_data *data, int x, int y)
{
	data->map_array->moves++;
	if (y == data->map_array->exit_y && x == data->map_array->exit_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->exit[0], x * data->img->img_px, y * data->img->img_px);
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
			data->img->exit[4], data->map_array->exit_x * data->img->img_px,
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
		win_and_lose_game(data, new_x, new_y);
		update_window_sprites(data, x, y);
		player_animation(data, new_x, new_y, dir);
		counter_on_screen(data);
		data->map_array->map[new_y][new_x] = 'P';
		data->map_array->start_x = new_x;
		data->map_array->start_y = new_y;
	}
}

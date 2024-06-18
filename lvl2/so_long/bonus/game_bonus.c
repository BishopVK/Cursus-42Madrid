/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:04:10 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/18 09:25:15 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	clean_up_img_arrays(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->img->player[i])
			mlx_destroy_image(data->mlx_ptr, data->img->player[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (data->img->exit[i])
			mlx_destroy_image(data->mlx_ptr, data->img->exit[i]);
		i++;
	}
}

void	clean_up(t_data *data)
{
	if (data->img)
	{
		clean_up_img_arrays(data);
		if (data->img->collec)
			mlx_destroy_image(data->mlx_ptr, data->img->collec);
		if (data->img->wall)
			mlx_destroy_image(data->mlx_ptr, data->img->wall);
		if (data->img->wall_border)
			mlx_destroy_image(data->mlx_ptr, data->img->wall_border);
		if (data->img->back)
			mlx_destroy_image(data->mlx_ptr, data->img->back);
		if (data->img->enemy)
			mlx_destroy_image(data->mlx_ptr, data->img->enemy);
		free(data->img);
		data->img = NULL;
	}
}

void	free_mlx_resources(t_data *data)
{
	free_array(data->map_array);
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

void	verify_map_size(t_map_array *map_array, t_data *data)
{
	if (map_array->width * 64 > data->screen_width
		|| map_array->height * 64 > data->screen_height)
	{
		ft_dprintf(2, "Error\n> The map is higger than screen resolution\n");
		on_destroy(data);
		exit (EXIT_FAILURE);
	}
}

void	initialize_game(t_map_chars *map_chars, t_map_array *map_array)
{
	t_data	data;

	map_array->chars = map_chars;
	data.map_array = map_array;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit (1);
	mlx_get_screen_size(data.mlx_ptr, &data.screen_width, &data.screen_height);
	data.img = NULL;
	data.win_ptr = mlx_new_window(data.mlx_ptr, map_array->width * 64,
			map_array->height * 64, "danjimen's game!");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		exit (1);
	}
	verify_map_size(map_array, &data);
	put_images(&data, map_array);
	initialize_screen_counter(&data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	free_mlx_resources(&data);
}

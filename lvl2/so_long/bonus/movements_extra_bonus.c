/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_extra_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:05:00 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/18 09:25:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_screen_counter(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->map_array->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 25, 0x000000, moves);
	free(moves);
}

void	counter_on_screen(t_data *data)
{
	char	*moves;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->wall,
		0 * data->img->img_px, 0 * data->img->img_px);
	moves = ft_itoa(data->map_array->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 25, 0x000000, moves);
	free(moves);
}

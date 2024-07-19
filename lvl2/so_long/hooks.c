/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:23:28 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/19 10:04:17 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		move_player(data, UP_KEY);
	else if (keysym == DOWN_KEY || keysym == S_KEY)
		move_player(data, DOWN_KEY);
	else if (keysym == RIGHT_KEY || keysym == D_KEY)
		move_player(data, RIGHT_KEY);
	else if (keysym == LEFT_KEY || keysym == A_KEY)
		move_player(data, LEFT_KEY);
	else if (keysym == ESC_KEY)
		on_destroy(data);
	return (0);
}

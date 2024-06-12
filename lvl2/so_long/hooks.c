/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:23:28 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/12 20:09:02 by danjimen         ###   ########.fr       */
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
	{
		ft_printf("Moved Up\n");
		move_player(data, UP_KEY);
	}
	else if (keysym == DOWN_KEY || keysym == S_KEY)
	{
		ft_printf("Moved Down\n");
		move_player(data, DOWN_KEY);
	}
	else if (keysym == RIGHT_KEY || keysym == D_KEY)
	{
		ft_printf("Moved Right\n");
		move_player(data, RIGHT_KEY);
	}
	else if (keysym == LEFT_KEY || keysym == A_KEY)
	{
		ft_printf("Moved Left\n");
		move_player(data, LEFT_KEY);
	}
	else if (keysym == ESC_KEY)
	{
		ft_printf("Pressed ESC key\n");
		on_destroy(data);
	}
	else
		ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

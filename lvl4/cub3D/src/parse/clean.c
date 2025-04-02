/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:52:43 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/02 16:01:38 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_element(char **element)
{
	int	i;

	i = 0;
	if (element)
	{
		while (element[i])
		{
			free (element[i]);
			element[i] = NULL;
			i++;
		}
		free (element);
		element = NULL;
	}
}

void	free_elements(t_map *map_s)
{
	free_element(map_s->north);
	free_element(map_s->south);
	free_element(map_s->west);
	free_element(map_s->east);
	free_element(map_s->floor->element);
	free_element(map_s->ceiling->element);
}

void	exit_map_error(t_map *map_s, char *message, int fd)
{
	if (map_s->chars->buffer != NULL)
		free(map_s->chars->buffer);
	if (map_s->chars->buffer_trimed != NULL)
		free(map_s->chars->buffer_trimed);
	free_elements(map_s);
	free_double_pointer(map_s->map);
	if (fd > 0)
	{
		get_next_line(fd, true);
		close (fd);
	}
	ft_dprintf(2, "Error\n> %s\n", message);
	exit (EXIT_FAILURE);
}

void	free_double_pointer(char **pointer)
{
	int	i;

	i = 0;
	if (pointer)
	{
		while (pointer[i])
		{
			free(pointer[i]);
			pointer[i] = NULL;
			i++;
		}
	}
	free (pointer);
	pointer = NULL;
}

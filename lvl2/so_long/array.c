/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:14:10 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/03 12:24:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(t_map_array *map_array)
{
	int	i;

	i = 0;
	while (i < map_array->height)
	{
		free(map_array->map[i]);
		i++;
	}
	free(map_array->map);
}

void	display_array(t_map_array *map_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_array->height)
	{
		j = 0;
		while (j < map_array->width)
		{
			ft_printf("%c ", map_array->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	initialize_array(char *buffer, t_map_array *map_array, int map_lines)
{
	int	j;

	j = 0;
	while (j < map_array->width)
	{
		map_array->map[map_lines][j] = buffer[j];
		j++;
	}
}

void	create_array(t_map_array *map_array)
{
	int	i;
	int	j;

	i = 0;
	map_array->map = (char **)malloc((map_array->height + 1) * sizeof(char *));
	while (i < map_array->height)
	{
		map_array->map[i] = (char *)malloc((map_array->width + 1) * sizeof(char));
		j = 0;
		while (j < map_array->width)
		{
			map_array->map[i][j] = 'X';
			j++;
		}
		map_array->map[i][j] = '\0';
		i++;
	}
	map_array->map[i] = NULL;
}

void	read_to_create_array(char *map, t_map_array *map_array)
{
	int		fd;
	int		map_lines;
	char	*buffer;

	map_lines = 0;
	buffer = NULL;
	create_array(map_array);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(buffer, "Open error", fd);
	buffer = get_next_line(fd);
	if (buffer == NULL)
		exit_map_error(buffer, "Failed to allocate memory for buffer", fd);
	while (buffer != NULL)
	{
		if (buffer == NULL) // Check if memory was allocated correctly
			exit_map_error(buffer, "Failed to allocate memory for buffer", fd);
		initialize_array(buffer, map_array, map_lines);
		detect_player(buffer, map_array, map_lines); // POSIBLEMENTE IRÁ AQUÍ!
		if (buffer != NULL)
			free(buffer); // Release the memory allocated to the line
		buffer = get_next_line(fd);
		map_lines++;
	}
	close(fd);
	// if (close(fd) == -1)
	// 	exit_map_error(buffer, "Close error");
}

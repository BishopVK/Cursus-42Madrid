/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:14:10 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/28 23:17:15 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	free_array(t_map_array *map_array)
{
	int	i;

	i = 0;
	if (map_array->map[i])
	{
		while (i < map_array->height)
		{
			free(map_array->map[i]);
			i++;
		}
		free(map_array->map);
	}
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
		map_array->map[i] = (char *)malloc((map_array->width + 1)
				* sizeof(char));
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
	buffer = get_next_line(fd, FALSE);
	if (buffer == NULL)
		exit_map_error(buffer, "Failed to allocate memory for buffer", fd);
	while (buffer != NULL)
	{
		if (buffer == NULL)
			exit_map_error(buffer, "Failed to allocate memory for buffer", fd);
		initialize_array(buffer, map_array, map_lines);
		detect_player_and_exit(buffer, map_array, map_lines);
		if (buffer != NULL)
			free(buffer);
		buffer = get_next_line(fd, FALSE);
		map_lines++;
	}
	close(fd);
} */

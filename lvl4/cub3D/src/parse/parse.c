/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:05:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/01 18:26:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* int	count_buffer_len(char *buffer, int fd)
{
	static size_t	buffer_len;

	if (buffer_len == 0)
	{
		if (buffer[ft_strlen(buffer) - 1] != '\n')
			exit_map_error(buffer, "Wrong map size", fd);
		buffer_len = (ft_strlen(buffer) - 1);
		if (buffer_len < 3)
			exit_map_error(buffer, "The map must have at least 3 columns", fd);
	}
	else if (buffer[ft_strlen(buffer) - 1] == '\n')
	{
		if ((ft_strlen(buffer) - 1) != buffer_len)
			exit_map_error(buffer, "Wrong map size", fd);
	}
	else
	{
		if (ft_strlen(buffer) != buffer_len)
			exit_map_error(buffer, "Wrong map size", fd);
	}
	return (buffer_len);
} */

static void	read_lines(t_map_array *map_array, int fd, int *last_map_line)
{
	while (map_array->chars->buffer != NULL)
	{
		map_array->file_lines++;
		map_array->chars->buffer_trimed = ft_strtrim_isspace(map_array->chars->buffer);
		if (map_array->chars->buffer[0] != '\n' && ft_strlen(map_array->chars->buffer_trimed) > 0)
		{
			if (map_array->chars->buffer_trimed[0] != '1')
				detect_map_elements(map_array, fd);
			else
			{
				if ((!map_array->north || !map_array->south || !map_array->west
					|| !map_array->east || !map_array->floor->element
					|| !map_array->ceiling->element) || (*last_map_line != 0
					&& map_array->file_lines != (*last_map_line + 1)))
					exit_map_error(map_array, "Void line in middle of the map or missing elements", fd);
				printf("%s", map_array->chars->buffer); // DB
				*last_map_line = map_array->file_lines;
				map_array->map_height++;
			}
		}
		free(map_array->chars->buffer);
		free(map_array->chars->buffer_trimed);
		map_array->chars->buffer = get_next_line(fd, false);
	}
}

static void	read_map_lines(char *map, t_map_array *map_array)
{
	int		fd;
	int	last_map_line;

	last_map_line = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(map_array, "Open error", fd);
	map_array->chars->buffer = get_next_line(fd, false);
	if (map_array->chars->buffer == NULL || ft_strlen(map_array->chars->buffer) == 0)
		exit_map_error(map_array, "Void map file", fd);
	read_lines(map_array, fd, &last_map_line);
	close(fd);
	map_array->chars->buffer = NULL;
	map_array->chars->buffer_trimed = NULL;
	print_elements(map_array); // DB
	printf("Map have %i lines\n", map_array->map_height); // DB
}

void	read_map(char *map, t_map_array *map_array)
{
	read_map_lines(map, map_array);
	if (map_array->north && map_array->south && map_array->west
		&& map_array->east && map_array->floor->element
		&& map_array->ceiling->element)
	{
		check_elements(map_array);
		print_rgb_values(map_array->floor); // DB
		print_rgb_values(map_array->ceiling); // DB
		save_map(map, map_array);
		print_map(map_array); // DB
	}
	else
		exit_map_error(map_array, "Missing elements", -1);
	/* if (map_array->height < 3)
		exit_map_error(buffer, "The map must have at least 3 lines", -1);
	map_array->width = read_for_check_borders(buffer, map,
			map_array->height, map_chars); */
}

void	check_arg_extension(char *map)
{
	int	map_len;
	int	map_name_len;

	map_len = ft_strlen(map);
	map_name_len = map_len - 4;
	if (!(ft_strncmp(map + map_name_len, ".cub", 4) == 0 && map_len > 4
			&& map[map_len - 5] != '/'))
	{
		ft_dprintf(STDERR_FILENO, "Error\n> Wrong file extension\n");
		exit (EXIT_FAILURE);
	}
}

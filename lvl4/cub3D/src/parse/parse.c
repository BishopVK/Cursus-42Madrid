/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:05:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/02 20:44:09 by danjimen         ###   ########.fr       */
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

static void	set_map_width(t_map *map_s)
{
	if (ft_strlen(map_s->chars->buffer_trimed) > map_s->map_max_width)
		map_s->map_max_width = ft_strlen(map_s->chars->buffer_trimed);
}

static void	read_lines(t_map *map_s, int fd, int *last_map_line)
{
	while (map_s->chars->buffer != NULL)
	{
		map_s->file_lines++;
		map_s->chars->buffer_trimed = ft_strtrim_isspace(map_s->chars->buffer);
		if (map_s->chars->buffer[0] != '\n'
			&& ft_strlen(map_s->chars->buffer_trimed) > 0)
		{
			if (map_s->chars->buffer_trimed[0] != '1')
				detect_map_elements(map_s, fd);
			else
			{
				if ((!map_s->north || !map_s->south || !map_s->west
						|| !map_s->east || !map_s->floor->element
						|| !map_s->ceiling->element) || (*last_map_line != 0
						&& map_s->file_lines != (*last_map_line + 1)))
					exit_map_error(map_s, "NL in map or missing elements", fd);
				printf("%s", map_s->chars->buffer); // DB
				*last_map_line = map_s->file_lines;
				map_s->map_height++;
			}
		}
		set_map_width(map_s);
		free(map_s->chars->buffer);
		free(map_s->chars->buffer_trimed);
		map_s->chars->buffer = get_next_line(fd, false);
	}
}

static void	read_map_lines(char *map_file, t_map *map_s)
{
	int		fd;
	int		last_map_line;

	last_map_line = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_map_error(map_s, "Open error", fd);
	map_s->chars->buffer = get_next_line(fd, false);
	if (map_s->chars->buffer == NULL
		|| ft_strlen(map_s->chars->buffer) == 0)
		exit_map_error(map_s, "Void map file", fd);
	read_lines(map_s, fd, &last_map_line);
	close(fd);
	map_s->chars->buffer = NULL;
	map_s->chars->buffer_trimed = NULL;
	print_elements(map_s); // DB
	check_map_size(map_s);
}

void	read_map(char *map_file, t_map *map_s)
{
	read_map_lines(map_file, map_s);
	if (map_s->north && map_s->south && map_s->west
		&& map_s->east && map_s->floor->element
		&& map_s->ceiling->element)
	{
		check_elements(map_s);
		print_rgb_values(map_s->floor); // DB
		print_rgb_values(map_s->ceiling); // DB
		save_map(map_file, map_s, 0);
		check_map_chars(map_s, 0, 0);
		printf("Map have %i lines\n", map_s->map_height); // DB
		printf("Longest line have %li chars\n", map_s->map_max_width); // DB
		printf("The Map have %i chars\n", map_s->total_map_chars); // DB
		print_map(map_s); // DB
	}
	else
		exit_map_error(map_s, "Missing elements", -1);
	/* if (map_s->height < 3)
		exit_map_error(buffer, "The map must have at least 3 lines", -1);
	map_s->width = read_for_check_borders(buffer, map,
			map_s->height, map_chars); */
}

void	check_arg_extension(char *map_file)
{
	int	map_len;
	int	map_name_len;

	map_len = ft_strlen(map_file);
	map_name_len = map_len - 4;
	if (!(ft_strncmp(map_file + map_name_len, ".cub", 4) == 0 && map_len > 4
			&& map_file[map_len - 5] != '/'))
	{
		ft_dprintf(STDERR_FILENO, "Error\n> Wrong file extension\n");
		exit (EXIT_FAILURE);
	}
}

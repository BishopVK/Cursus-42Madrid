/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:04:30 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/14 17:59:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_map_error(char *buffer, char *message, int fd)
{
	if (buffer != NULL)
		free(buffer);
	get_next_line(fd, TRUE);
	ft_dprintf(2, "Error\n> %s\n", message);
	exit (EXIT_FAILURE);
}

int	count_buffer_len(char *buffer, int fd)
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
}

int	read_map_lines(char *buffer, char *map)
{
	int	fd;
	int	map_lines;

	map_lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(buffer, "Open error", fd);
	buffer = get_next_line(fd, FALSE);
	if (buffer == NULL || ft_strlen(buffer) == 0)
		exit_map_error(buffer, "Void map file", fd);
	while (buffer != NULL)
	{
		if (buffer[0] == '\n')
			exit_map_error(buffer, "Only new line detected", fd);
		count_buffer_len(buffer, fd);
		check_map_characters(buffer, "01CEPK", fd);
		if (ft_strlen(buffer) > 256 || map_lines > 256)
			exit_map_error(buffer, "The map is too big", fd);
		free(buffer);
		buffer = get_next_line(fd, FALSE);
		map_lines++;
	}
	close(fd);
	return (map_lines);
}

void	read_map(char *map, t_map_chars *map_chars, t_map_array *map_array)
{
	char	*buffer;

	buffer = NULL;
	map_array->height = read_map_lines(buffer, map);
	if (map_array->height < 3)
		exit_map_error(buffer, "The map must have at least 3 lines", -1);
	map_array->width = read_for_check_borders(buffer, map,
			map_array->height, map_chars);
}

void	check_arg_extension(char *map)
{
	int	map_len;
	int	map_name_len;

	map_len = ft_strlen(map);
	map_name_len = map_len - 4;
	if (!(ft_strncmp(map + map_name_len, ".ber", 4) == 0 && map_len > 4
			&& map[map_len - 5] != '/'))
	{
		ft_dprintf(2, "Error\n> Wrong file extension\n");
		exit (-1);
	}
}

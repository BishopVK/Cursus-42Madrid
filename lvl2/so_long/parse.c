/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:05:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/23 18:00:48 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_map_error(char *buffer, char *message)
{
	if (buffer != NULL)
	{
		ft_dprintf(2, "Buffer before free: %s\n", buffer);
		free(buffer);
	}
	ft_dprintf(2, "%s\n", message);
	exit (EXIT_FAILURE);
}

int	count_buffer_len(char *buffer)
{
	static size_t	buffer_len;

	if (buffer_len == 0)
	{
		ft_printf("ft_strlen(buffer) => %i\n", ft_strlen(buffer));
		//ft_dprintf(2, "THIS SHOULD ONLY COME ONE TIME\n");
		if (buffer[ft_strlen(buffer) - 1] != '\n')
			exit_map_error(buffer, "Wrong map size"); // 1 line map
		buffer_len = (ft_strlen(buffer) - 1);
		if (buffer_len < 3)
			exit_map_error(buffer, "The map must have at least 3 columns"); // At least 3 cols
		ft_printf("buffer_len => %i\n", buffer_len);
	}
	else if (buffer[ft_strlen(buffer) - 1] == '\n')
	{
		//ft_dprintf(2, "IF there is a line break\n");
		if ((ft_strlen(buffer) - 1) == buffer_len)
			ft_dprintf(2, "Lines of the same length\n");
		else
			exit_map_error(buffer, "Wrong map size"); //Different line len
	}
	else
	{
		//ft_dprintf(2, "NO line break\n");
		ft_printf("LAST LINE: ft_strlen(buffer) => %i", ft_strlen(buffer));
		if (ft_strlen(buffer) == buffer_len)
			ft_dprintf(2, "\nLines of the same length\n");
		else
			exit_map_error(buffer, "Wrong map size"); //Different line len
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
		exit_map_error(buffer, "Open error");
	buffer = get_next_line(fd);
	if (buffer == NULL || ft_strlen(buffer) == 0)
		exit_map_error(buffer, "Void map file"); //Void map
	while (buffer != NULL)
	{
		if (buffer == NULL) // Check if memory was allocated correctly
			exit_map_error(buffer, "Failed to allocate memory for buffer"); //Void map
		if (buffer[0] == '\n')
			exit_map_error(buffer, "Only new line detected"); // First line void
		ft_printf("\n%s", buffer); // Show the line read (DELETE)
		count_buffer_len(buffer); // Count buffer length
		check_map_characters(buffer, "01CEP"); // Check characters
		if (buffer != NULL)
			free(buffer); // Release the memory allocated to the line
		buffer = get_next_line(fd);
		map_lines++;
	}
	if (close(fd) == -1)
		exit_map_error(buffer, "Close error");
	return (map_lines);
}

void	read_map(char *map, t_map_chars *map_chars, t_map_array *map_array)
{
	char	*buffer;

	buffer = NULL;
	map_array->height = read_map_lines(buffer, map);
	ft_printf("map_lines => %i\n", map_array->height);
	if (map_array->height < 3)
		exit_map_error(buffer, "The map must have at least 3 lines");
	map_array->width = read_for_check_borders(buffer, map, map_array->height, map_chars); // Check borders
}

void	check_arg_extension(char *map)
{
	int	map_len;
	int	map_name_len;

	map_len = ft_strlen(map);
	map_name_len = map_len - 4;
	if (ft_strncmp(map + map_name_len, ".ber", 4) == 0 && map_len > 4
		&& map[map_len - 5] != '/')
		ft_printf("Correct \"%s\" file extension\n", map + map_name_len);
	else
	{
		ft_dprintf(2, "Wrong file extension\n");
		exit (-1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:05:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/31 00:00:41 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_element(char **element)
{
	int	i;

	i = 0;
	if (element)
	{
		while (element[i])
		{
			free (element[i]);
			i++;
		}
		free (element);
	}
}

void	free_elements(t_map_array *map_array)
{
	free_element(map_array->north);
	free_element(map_array->south);
	free_element(map_array->west);
	free_element(map_array->east);
	free_element(map_array->floor);
	free_element(map_array->ceiling);
}

void	exit_map_error(t_map_array *map_array, char *message, int fd)
{
	if (map_array->chars->buffer != NULL)
		free(map_array->chars->buffer);
	get_next_line(fd, true);
	ft_dprintf(2, "Error\n> %s\n", message);
	close (fd);
	exit (EXIT_FAILURE);
}

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

static void	print_element(char **element)
{
	int	i;

	i = 0;
	if (element)
	{
		while (element[i])
		{
			printf ("%s ", element[i]);
			i++;
		}
		printf("\n");
	}
}

void	print_elements(t_map_array *map_array)
{
	print_element(map_array->north);
	print_element(map_array->south);
	print_element(map_array->west);
	print_element(map_array->east);
	print_element(map_array->floor);
	print_element(map_array->ceiling);
}

static void	keep_map_elements(char ***element, t_map_array *map_array, int fd)
{
	if (*element == NULL)
	{
		printf ("%s IS VOID\n", map_array->chars->buffer_trimed);
		*element = ft_split_isspace(map_array->chars->buffer_trimed);
	}
	else
	{
		print_element(*element);
		free (map_array->chars->buffer_trimed);
		free_elements(map_array);
		exit_map_error(map_array, "Repeated map element", fd);
	}
}

static void	detect_map_elements(t_map_array *map_array, int fd)
{
	if (ft_strlen(map_array->chars->buffer_trimed) > 3)
	{
		if (map_array->chars->buffer_trimed[0] == 'N' && map_array->chars->buffer_trimed[1] == 'O')
			keep_map_elements(&map_array->north, map_array, fd);
		else if (map_array->chars->buffer_trimed[0] == 'S' && map_array->chars->buffer_trimed[1] == 'O')
			keep_map_elements(&map_array->south, map_array, fd);
		else if (map_array->chars->buffer_trimed[0] == 'W' && map_array->chars->buffer_trimed[1] == 'E')
			keep_map_elements(&map_array->west, map_array, fd);
		else if (map_array->chars->buffer_trimed[0] == 'E' && map_array->chars->buffer_trimed[1] == 'A')
			keep_map_elements(&map_array->east, map_array, fd);
		else if (map_array->chars->buffer_trimed[0] == 'F')
			keep_map_elements(&map_array->floor, map_array, fd);
		else if (map_array->chars->buffer_trimed[0] == 'C')
			keep_map_elements(&map_array->ceiling, map_array, fd);
	}
}


void	read_map_lines(char *map, t_map_array *map_array)
{
	int		fd;
	//char	*buffer_trimed;
	//int	map_lines;

	//map_lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(map_array, "Open error", fd);
	map_array->chars->buffer = get_next_line(fd, false);
	if (map_array->chars->buffer == NULL || ft_strlen(map_array->chars->buffer) == 0)
		exit_map_error(map_array, "Void map file", fd);
	while (map_array->chars->buffer != NULL)
	{
		map_array->chars->buffer_trimed = ft_strtrim_isspace(map_array->chars->buffer);
		if (map_array->chars->buffer[0] != '\n' && ft_strlen(map_array->chars->buffer_trimed) > 0)
		{
			if (map_array->chars->buffer_trimed[0] != '1')
				detect_map_elements(map_array, fd);
			else
				printf("%s is part of the map\n", map_array->chars->buffer);
		}
		/* count_buffer_len(buffer, fd);
		check_map_characters(buffer, "01CEP", fd); */
		/* if (ft_strlen(buffer) > 256)
			exit_map_error(buffer, "The map is too big", fd); */
		free(map_array->chars->buffer);
		free(map_array->chars->buffer_trimed);
		map_array->chars->buffer = get_next_line(fd, false);
		//map_lines++;
	}
	print_elements(map_array);
	close(fd);
}

void	read_map(char *map, t_map_array *map_array)
{
	read_map_lines(map, map_array);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:05:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/01 14:21:43 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_element(char **element)
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
	if (map_array->chars->buffer_trimed != NULL)
		free(map_array->chars->buffer_trimed);
	free_elements(map_array);
	free_double_pointer(map_array->map);
	if (fd > 0)
	{
		get_next_line(fd, true);
		close (fd);
	}
	ft_dprintf(2, "Error\n> %s\n", message);
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
		printf ("%s IS VOID\n", map_array->chars->buffer_trimed); // DB
		*element = ft_split_isspace(map_array->chars->buffer_trimed);
	}
	else
	{
		print_element(*element); // DB
		exit_map_error(map_array, "Repeated map element", fd);
	}
}

static void	detect_map_elements(t_map_array *map_array, int fd)
{
	char	*trimed;

	trimed = map_array->chars->buffer_trimed;
	if (ft_strlen(map_array->chars->buffer_trimed) > 3)
	{
		if (trimed[0] == 'N' && trimed[1] == 'O' && ft_isspace(trimed[2]))
			keep_map_elements(&map_array->north, map_array, fd);
		else if (trimed[0] == 'S' && trimed[1] == 'O' && ft_isspace(trimed[2]))
			keep_map_elements(&map_array->south, map_array, fd);
		else if (trimed[0] == 'W' && trimed[1] == 'E' && ft_isspace(trimed[2]))
			keep_map_elements(&map_array->west, map_array, fd);
		else if (trimed[0] == 'E' && trimed[1] == 'A' && ft_isspace(trimed[2]))
			keep_map_elements(&map_array->east, map_array, fd);
		else if (trimed[0] == 'F' && ft_isspace(trimed[1]))
			keep_map_elements(&map_array->floor, map_array, fd);
		else if (trimed[0] == 'C' && ft_isspace(trimed[1]))
			keep_map_elements(&map_array->ceiling, map_array, fd);
		else
		{
			printf("%s", map_array->chars->buffer); // DB
			exit_map_error(map_array, "Not a valid element detected", fd);
		}
	}
	else
		exit_map_error(map_array, "Not a valid element detected", fd);
}

void save_map(char *map, t_map_array *map_array)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(map_array, "Open error", fd);
	map_array->chars->buffer = get_next_line(fd, false);
	map_array->map = malloc((map_array->map_height + 1) * sizeof(char *));
	while (map_array->chars->buffer != NULL)
	{
		map_array->chars->buffer_trimed = ft_strtrim_isspace(map_array->chars->buffer);
		if (map_array->chars->buffer[0] != '\n'
			&& ft_strlen(map_array->chars->buffer_trimed) > 0
			&& map_array->chars->buffer_trimed[0] == '1')
		{
			printf("Se va a guardar en map_array->map[%i]: %s", i, map_array->chars->buffer); // DB
			map_array->map[i++] = ft_strdup(map_array->chars->buffer);
		}
		free(map_array->chars->buffer);
		free(map_array->chars->buffer_trimed);
		map_array->chars->buffer = get_next_line(fd, false);
	}
	map_array->map[i] = NULL;
}

void	print_map(t_map_array *map_array)
{
	int	i;

	i = 0;
	printf("\n-- MAP SAVED --\n");
	while (map_array->map[i])
	{
		printf("%s", map_array->map[i]);
		i++;
	}
	printf("\n");
}

void	check_element_path(t_map_array *map_array, char **element, int count)
{
	int	i;
	int	fd;

	i = 0;
	while (element[i])
	{
		if (i == 1)
		{
			fd = open(element[i], O_RDONLY);
			if (fd == -1)
			{
				if (errno == ENOENT)
					exit_map_error(map_array, "Texture file does not exist", fd);
				else if (errno == EACCES)
					exit_map_error(map_array, "Texture file is not readable", fd);
				else
					exit_map_error(map_array, "Error opening texture file", fd);
			}
			close(fd);
		}				
		count++;
		i++;
	}
	if (count != 2)
		exit_map_error(map_array, "The texture element is incorrect", -1);
}

void	check_element_rgb(t_map_array *map_array, char **element)
{
	int	i;
	int	j;
	int	k;
	int	count_elements;
	char	**splited;
	int	count_colors;

	i = 0;
	count_elements = 0;
	while (element[i])
	{
		if (i == 1)
		{
			splited = ft_split(element[i], ',');
			j = 0;
			count_colors = 0;
			while (splited[j])
			{
				k = 0;
				while (splited[j][k])
				{
					if (!ft_isdigit(splited[j][k]))
					{
						free_double_pointer(splited);
						exit_map_error(map_array, "Invalid RGB value", -1);
					}
					k++;
				}
				if (ft_atoi(splited[j]) < 0 || ft_atoi(splited[j]) > 255)
				{
					free_double_pointer(splited);
					exit_map_error(map_array, "Invalid RGB range color", -1);
				}
				count_colors++;
				j++;
			}
			if (count_colors != 3)
			{
				free_double_pointer(splited);
				exit_map_error(map_array, "Invalid RGB color", -1);
			}
			free_double_pointer(splited);
		}
		count_elements++;
		i++;
	}
	if (count_elements != 2)
		exit_map_error(map_array, "The RGB element is incorrect", -1);
}

void	check_elements(t_map_array *map_array)
{
	check_element_path(map_array, map_array->north, 0);
	check_element_path(map_array, map_array->south, 0);
	check_element_path(map_array, map_array->west, 0);
	check_element_path(map_array, map_array->east, 0);
	check_element_rgb(map_array, map_array->floor);
	check_element_rgb(map_array, map_array->ceiling);
}

void	read_map_lines(char *map, t_map_array *map_array)
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
					|| !map_array->east || !map_array->floor
					|| !map_array->ceiling) || (last_map_line != 0
					&& map_array->file_lines != (last_map_line + 1)))
					exit_map_error(map_array, "Void line in middle of the map or missing elements", fd);
				printf("%s", map_array->chars->buffer); // DB
				last_map_line = map_array->file_lines;
				map_array->map_height++;
			}
		}
		free(map_array->chars->buffer);
		free(map_array->chars->buffer_trimed);
		map_array->chars->buffer = get_next_line(fd, false);
	}
	close(fd);
	map_array->chars->buffer = NULL;
	map_array->chars->buffer_trimed = NULL;
	print_elements(map_array); // DB
	printf("Map have %i lines\n", map_array->map_height); // DB
	if (map_array->north && map_array->south && map_array->west && map_array->east && map_array->floor && map_array->ceiling)
	{
		check_elements(map_array);
		save_map(map, map_array);
		print_map(map_array);
	}
	else
		exit_map_error(map_array, "Missing elements", -1);

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

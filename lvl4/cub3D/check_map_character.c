/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:46:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/28 23:17:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	check_nbr_chars(char *buffer, t_map_chars *map_chars, int fd)
{
	if (map_chars->exit != 1 || map_chars->player != 1
		|| map_chars->collectible < 1)
		exit_map_error(buffer,
			"Incorrect number of players, exits or collectibles", fd);
}

void	count_nbr_chars(char *buffer, t_map_chars *map_chars)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '0')
			map_chars->empty++;
		else if (buffer[i] == '1')
			map_chars->wall++;
		else if (buffer[i] == 'C')
			map_chars->collectible++;
		else if (buffer[i] == 'E')
			map_chars->exit++;
		else if (buffer[i] == 'P')
			map_chars->player++;
		i++;
	}
}

void	check_borders(char *buffer, int total_lines, int map_line, int fd)
{
	int	i;

	i = 0;
	if (map_line == 0 || map_line == total_lines - 1)
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			if (buffer[i++] != '1')
				exit_map_error(buffer, "Incorrect first or last border", fd);
	}
	else
	{
		if (buffer[ft_strlen(buffer) - 1] == '\n')
		{
			if (buffer[0] != '1' || buffer[ft_strlen(buffer) - 2] != '1')
				exit_map_error(buffer, "Incorrect left or right border", fd);
		}
		else
		{
			if (buffer[0] != '1' || buffer[ft_strlen(buffer) - 1] != '1')
				exit_map_error(buffer, "Incorrect left or right border", fd);
		}
	}
}

int	read_for_check_borders(char *buffer, char *map, int total_lines,
	t_map_chars *map_chars)
{
	int	fd;
	int	map_line;
	int	buffer_len;

	map_line = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(buffer, "Open error", fd);
	buffer = get_next_line(fd, FALSE);
	if (buffer == NULL)
		exit_map_error(buffer, "Failed to allocate memory for buffer", fd);
	while (buffer != NULL)
	{
		check_borders(buffer, total_lines, map_line, fd);
		count_nbr_chars(buffer, map_chars);
		buffer_len = count_buffer_len(buffer, fd);
		if (buffer != NULL)
			free(buffer);
		buffer = get_next_line(fd, FALSE);
		map_line++;
	}
	check_nbr_chars(buffer, map_chars, fd);
	close(fd);
	return (buffer_len);
}

void	check_map_characters(char *buffer, char *allowed, int fd)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (buffer != NULL && buffer[i] != '\n' && buffer[i] != '\0')
	{
		found = 0;
		j = 0;
		while (allowed[j] != '\0')
		{
			if (buffer[i] == allowed[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			exit_map_error(buffer, "Not allowed map characters", fd);
		i++;
	}
} */

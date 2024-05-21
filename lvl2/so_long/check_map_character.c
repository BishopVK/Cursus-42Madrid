/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:46:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/21 09:35:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_borders(char *buffer, int total_lines, int map_line)
{
	int	i;

	i = 0;
	ft_printf("total_lines ==> %i\n", total_lines);
	ft_printf("map_line ==> %i\n", map_line);
	if (map_line == 0 || map_line == total_lines - 1) // First or last line
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			if (buffer[i++] != '1')
				exit_map_error(buffer, 1, "Incorrect first or last border");
	}
	else
	{
		if (buffer[ft_strlen(buffer) - 1] == '\n')
		{
			if (buffer[0] != '1' || buffer[ft_strlen(buffer) - 2] != '1')
				exit_map_error(buffer, 1, "Incorrect left or right border");
		}
		else
		{
			if (buffer[0] != '1' || buffer[ft_strlen(buffer) - 1] != '1')
				exit_map_error(buffer, 1, "Incorrect left or right border");
		}
	}
}

void	read_for_check_borders(char *buffer, char *map, int total_lines, t_map_chars *map_chars)
{
	int	fd;
	int	map_line;

	map_line = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(buffer, 0, "Open error");
	buffer = get_next_line(fd);
	if (buffer == NULL)
		exit_map_error(buffer, 0, "Failed to allocate memory for buffer"); //Void map
	while (buffer != NULL)
	{
		if (buffer == NULL) // Verificar si se asignó memoria correctamente
			exit_map_error(buffer, 0, "Failed to allocate memory for buffer"); //Void map
		ft_printf("-----------\n"); // Mostrar separador (BORRAR)
		ft_printf("\n%s", buffer); // Mostrar la línea leída (BORRAR)
		check_borders(buffer, total_lines, map_line);
		count_nbr_chars(buffer, map_chars);
		free(buffer); // Liberar la memoria asignada a la línea
		buffer = get_next_line(fd);
		map_line++;
	}
	if (close(fd) == -1)
		exit_map_error(buffer, 0, "Close error");
}

void	check_map_characters(char *buffer, char *allowed)
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
			exit_map_error(buffer, 1, "Not allowed map characters");
		i++;
	}
}

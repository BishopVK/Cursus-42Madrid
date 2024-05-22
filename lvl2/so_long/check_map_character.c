/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:46:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/22 15:00:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nbr_chars(t_map_chars *map_chars)
{
	ft_printf("map_chars->empty ==> %i\n", map_chars->empty);
	ft_printf("map_chars->wall ==> %i\n", map_chars->wall);
	ft_printf("map_chars->collectible ==> %i\n", map_chars->collectible);
	ft_printf("map_chars->exit ==> %i\n", map_chars->exit);
	ft_printf("map_chars->player ==> %i\n", map_chars->player);
	if (map_chars->exit != 1 || map_chars->player != 1
		|| map_chars->collectible < 1)
	{
		ft_dprintf(2, "Incorrect number of players, exits or collectibles");
		exit (EXIT_FAILURE);
	}
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
				exit_map_error(buffer, "Incorrect first or last border");
	}
	else
	{
		if (buffer[ft_strlen(buffer) - 1] == '\n')
		{
			if (buffer[0] != '1' || buffer[ft_strlen(buffer) - 2] != '1')
				exit_map_error(buffer, "Incorrect left or right border");
		}
		else
		{
			if (buffer[0] != '1' || buffer[ft_strlen(buffer) - 1] != '1')
				exit_map_error(buffer, "Incorrect left or right border");
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
		exit_map_error(buffer, "Open error");
	buffer = get_next_line(fd);
	if (buffer == NULL)
		exit_map_error(buffer, "Failed to allocate memory for buffer"); //Void map
	while (buffer != NULL)
	{
		if (buffer == NULL) // Verificar si se asignó memoria correctamente
			exit_map_error(buffer, "Failed to allocate memory for buffer"); //Void map
		ft_printf("-----------\n"); // Mostrar separador (BORRAR)
		ft_printf("\n%s", buffer); // Mostrar la línea leída (BORRAR)
		check_borders(buffer, total_lines, map_line);
		count_nbr_chars(buffer, map_chars);
		buffer_len = count_buffer_len(buffer);
		if (buffer != NULL)
			free(buffer); // Liberar la memoria asignada a la línea
		buffer = get_next_line(fd);
		map_line++;
	}
	check_nbr_chars(map_chars);
	if (close(fd) == -1)
		exit_map_error(buffer, "Close error");
	return (buffer_len);
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
			exit_map_error(buffer, "Not allowed map characters");
		i++;
	}
}

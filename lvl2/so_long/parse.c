/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:05:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/20 13:24:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_map_error(char *buffer, int error_nbr, char *message)
{
	if (error_nbr == 0)
	{
		perror(message);
		exit (EXIT_FAILURE);
	}
	if (error_nbr == 1)
	{
		ft_dprintf(2, "%s\n", message);
		free(buffer);
		exit (-1);
	}
	if (error_nbr == 2)
	{
		ft_dprintf(2, "%s\n", message);
		free(buffer);
		exit (-1);
	}
}

static void	count_buffer_len(char *buffer)
{
	static size_t	buffer_len;

	if (buffer_len == 0)
	{
		ft_printf("ft_strlen(buffer) => %i\n", ft_strlen(buffer));
		//ft_dprintf(2, "ESTO SOLO DEBERIA SALIR 1 VEZ\n");
		if (buffer[ft_strlen(buffer) - 1] != '\n')
			exit_map_error(buffer, 2, "Wrong map size"); // 1 line map
		buffer_len = (ft_strlen(buffer) - 1);
		ft_printf("buffer_len => %i\n", buffer_len);
	}
	else if (buffer[ft_strlen(buffer) - 1] == '\n')
	{
		//ft_dprintf(2, "SI hay salto de línea\n");
		if ((ft_strlen(buffer) - 1) == buffer_len)
			ft_dprintf(2, "Líneas de la misma lóngitud\n");
		else
			exit_map_error(buffer, 2, "Wrong map size"); //Different line len
	}
	else
	{
		//ft_dprintf(2, "NO hay salto de línea\n");
		ft_printf("ft_strlen(buffer) => %i", ft_strlen(buffer));
		if (ft_strlen(buffer) == buffer_len)
			ft_dprintf(2, "\nLíneas de la misma lóngitud\n");
		else
			exit_map_error(buffer, 2, "Wrong map size"); //Different line len
	}
}

int	read_map_lines(char *buffer, char *map)
{
	int	fd;
	int	map_lines;

	map_lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(buffer, 0, "Open");
	buffer = get_next_line(fd);
	if (ft_strlen(buffer) == 0)
		exit_map_error(buffer, 1, "Void map file"); //Void map
	while (buffer != NULL)
	{
		// Verificar si se asignó memoria correctamente
		if (buffer == NULL)
		{
			ft_dprintf(2, "Failed to allocate memory for buffer\n");
			break;
		}
		ft_printf("\n%s", buffer); // Mostrar la línea leída
		count_buffer_len(buffer); // Contar la longitud del buffer
		free(buffer); // Liberar la memoria asignada a la línea
		buffer = get_next_line(fd);
		map_lines++;
	}
	if (close(fd) == -1)
		exit_map_error(buffer, 0, "Close");
	return (map_lines);
}

void	read_map(char *map)
{
	char	*buffer;
	int		map_lines;

	buffer = NULL;
	map_lines = read_map_lines(buffer, map);
	ft_printf("map_lines => %i\n", map_lines);
	/*
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(buffer, 0, "Open");
	buffer = get_next_line(fd);
	if (ft_strlen(buffer) == 0)
		exit_map_error(buffer, 1, "Void map file"); //Void map
	while (buffer != NULL)
	{
		// Verificar si se asignó memoria correctamente
		if (buffer == NULL)
		{
			ft_dprintf(2, "Failed to allocate memory for buffer\n");
			break;
		}
		// Mostrar la línea leída
		ft_printf("\n%s", buffer);
		// Contar la longitud del buffer
		count_buffer_len(buffer);
		// Liberar la memoria asignada a la línea
		free(buffer);

		buffer = get_next_line(fd);
	}
	// Cerrar el descriptor de archivo
	if (close(fd) == -1)
		exit_map_error(buffer, 0, "Close");
	*/
}

void	check_arg_extension(char *map)
{
	int	map_len;
	int	map_name_len;

	map_len = ft_strlen(map);
	map_name_len = map_len - 4;
	if (ft_strncmp(map + map_name_len, ".ber", 4) == 0)
		ft_printf("Correct \"%s\" file extension\n", map + map_name_len);
	else
	{
		ft_dprintf(2, "Wrong file extension: \"%s\"\n", map + map_name_len);
		exit (-1);
	}
}
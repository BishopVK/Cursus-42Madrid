/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:05:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/19 18:06:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_map_error(char *buffer, int error_nbr)
{
	if (error_nbr == 0)
	{
		ft_dprintf(2, "Void map file\n");
		free(buffer);
		exit (-1);
	}
	if (error_nbr == 1)
	{
		ft_dprintf(2, "Wrong map size\n");
		free(buffer);
		exit (-1);
	}
}

static void	count_buffer_len(char *buffer)
{
	static int	buffer_len;

	if (buffer_len == 0)
	{
		//ft_dprintf(2, "ESTO SOLO DEBERIA SALIR 1 VEZ\n");
		if (buffer[ft_strlen(buffer) - 1] != '\n')
			exit_map_error(buffer, 1); // 1 line map
		buffer_len = (ft_strlen(buffer) - 1);
		ft_printf("buffer_len => %i\n", buffer_len);
	}
	else if (buffer[ft_strlen(buffer) - 1] == '\n')
	{
		//ft_dprintf(2, "SI hay salto de línea\n");
		if ((buffer_len - (ft_strlen(buffer) - 1)) == 0)
			ft_dprintf(2, "Líneas de la misma lóngitud\n");
		else
			exit_map_error(buffer, 1); //Different line len
	}
	else
	{
		//ft_dprintf(2, "NO hay salto de línea\n");
		if ((buffer_len - ft_strlen(buffer)) == 0)
			ft_dprintf(2, "\nLíneas de la misma lóngitud\n");
		else
			exit_map_error(buffer, 1); //Different line len
	}
}

void	read_map(char *map)
{
	char	*buffer;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Open");
		exit(EXIT_FAILURE);
	}
	buffer = get_next_line(fd);
	if (ft_strlen(buffer) == 0)
		exit_map_error(buffer, 0); //Void map
	while (buffer != NULL)
	{
		// Verificar si se asignó memoria correctamente
		if (buffer == NULL)
		{
			fprintf(stderr, "Failed to allocate memory for buffer\n");
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
	{
		perror("Close");
		exit(EXIT_FAILURE);
	}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:33:09 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/07 11:33:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes_read;
	ssize_t		total_bytes_read;
	char		*result;

	if (BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = NULL;
	if (buffer == NULL)
		buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL)
		return (NULL);
	total_bytes_read = 0;
	bytes_read = read(fd, buffer + total_bytes_read, 1);
	while (bytes_read > 0)
	{
		if (buffer[total_bytes_read] == '\n')
		{
			buffer[total_bytes_read++] = '\0';
			result = ft_strdup(buffer);
			ft_memmove(buffer, buffer + total_bytes_read,
				BUFFER_SIZE - total_bytes_read + 1);
			free(buffer);
			return (result);
		}
		total_bytes_read++;
		if (total_bytes_read == BUFFER_SIZE)
		{
			buffer[total_bytes_read] = '\0';
			result = (ft_strdup(buffer));
			free(buffer);
			return (result);
		}
		bytes_read = read(fd, buffer + total_bytes_read, 1);
	}
	if (bytes_read < 0)
		return (NULL);
	if (total_bytes_read > 0)
	{
		buffer[total_bytes_read] = '\0';
		result = (ft_strdup(buffer));
		free(buffer);
		return (result);
	}
	return (NULL);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c -fsanitize=address -static-libasan
// ./a.out texto.txt

/* int	main(int argc, char *argv[])
{
	char	*buffer;

	if (argc != 2) {
		fprintf(stderr, "Uso: %s <nombre_del_archivo>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Abrir el archivo para lectura
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	// Llamar a la función para leer el contenido del archivo
	while ((buffer = get_next_line(fd)) != NULL) {
		// Verificar si se asignó memoria correctamente
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: Fallo al asignar memoria para el buffer\n");
			break;
		}

		// Procesar la línea leída
		printf("RECIBIDO: %s\n", buffer);

		// Liberar la memoria asignada a la línea
		free(buffer);
	}

	//printf("%s\n", buffer);

	//free(buffer);

	// Cerrar el descriptor de archivo
	if (close(fd) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	return (0);
} */
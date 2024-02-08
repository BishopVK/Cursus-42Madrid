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
	ssize_t 	bytes_read;
	char		*position;
	//char		*result;

	if (BUFFER_SIZE >= SIZE_MAX || BUFFER_SIZE <= 0)
		return (NULL);

	if (buffer == NULL)
		buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	//buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(1, (char *)buffer, bytes_read) != bytes_read)
		{
			perror("write");
			return (buffer);
		}
		buffer++;
	}

	// Verificar errores de lectura
	if (bytes_read < 0)
	{ 
		perror("read");
		return (buffer);
	}

	// Final del documento
	if (bytes_read == 0)
	{ 
		// Has alcanzado el final del archivo
		printf("Fin del archivo alcanzado.\n");
		return (NULL);
	}

	while (!buffer)
	{
		position = ft_strchr(buffer, '\n');
		if (position != NULL)
			printf("Se encontró el caracter '\n' en el índice %ld.\n", position - buffer);
		else
			printf("No encontró el caracter '\n'");
	}


	// Colocar el terminador nulo al final de la cadena
	//buffer[total_bytes_read] = '\0';

	return (buffer);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c
// ./a.out texto.txt

int	main(int argc, char *argv[])
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
		printf("%s\n", buffer); // Procesar la línea leída, si es necesario
		//free(buffer); // Liberar la memoria asignada a la línea
	}

	//printf("%s\n", buffer);

	free(buffer);

	// Cerrar el descriptor de archivo
	if (close(fd) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	return (0);
}
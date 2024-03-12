/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:12:38 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/12 19:40:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line_and_update_result(char **result, char *line)
{
	char	*tmp;

	ft_strlcpy(line, *result, (ft_strchr(*result, '\n') - *result) + 2);
	tmp = *result;
	*result = ft_strdup(ft_strchr(*result, '\n') + 1);
	free(tmp);
	return (line);
}

static char	*process_result(char **result)
{
	char	*line;

	if (ft_strchr(*result, '\n'))
	{
		line = (char *)malloc(ft_strchr(*result, '\n') - *result + 2);
		if (line == NULL)
			return (NULL);
		line = get_line_and_update_result(result, line);
	}
	else
	{
		line = (char *)malloc(ft_strlen(*result) + 1);
		if (line == NULL)
			return (NULL);
		if (line)
		{
			ft_strlcpy(line, *result, ft_strlen(*result) + 1);
			free(*result);
			*result = (NULL);
		}
	}
	return (line);
}

int	read_file(int fd, char **result, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr(*result, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*result);
			*result = ft_strdup("");
			return (-1);
		}
		buffer[bytes_read] = '\0';
		tmp = *result;
		*result = ft_strjoin(*result, buffer);
		free(tmp);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*result[FOPEN_MAX];
	char		*line;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	if (!result[fd])
		result[fd] = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read_file(fd, &result[fd], buffer);
	free(buffer);
	if (bytes_read <= 0 && ft_strlen(result[fd]) == 0)
	{
		free(result[fd]);
		result[fd] = NULL;
		return (NULL);
	}
	line = process_result(&result[fd]);
	return (line);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=100
// get_next_line_bonus.c get_next_line_utils_bonus.c
// ./a.out txt/texto.txt

//LECTURA DE FICHERO O DE STDIN
/* int	main(int argc, char *argv[]) {
	char *buffer;

	//Leer desde archivo si se proporciona al menos
	//un argumento en la línea de comandos
	if (argc > 1) {
		// Abrir y leer cada archivo secuencialmente
		for (int i = 1; i < argc; i++) {
			int fd = open(argv[i], O_RDONLY);
			if (fd == -1) {
				perror("open");
				exit(EXIT_FAILURE);
			}

			printf(COLOR_CYAN"\n>> CONTENIDO DEL ARCHIVO: %s:\n" COLOR_RESET,
				argv[i]);
			while ((buffer = get_next_line(fd)) != NULL) {
				// Verificar si se asignó memoria correctamente
				if (buffer == NULL) {
					fprintf(stderr, "Fallo al asignar memoria para el buffer\n");
					break;
				}
				// Procesar la línea leída
				printf("RECIBIDO: %s\n", buffer);

				// Liberar la memoria asignada a la línea
				free(buffer);
			}

			// Cerrar el descriptor de archivo
			if (close(fd) == -1) {
				perror("close");
				exit(EXIT_FAILURE);
			}
		}
	}
	// Leer desde stdin si no se proporcionan argumentos en la línea de comandos
	else if (argc == 1) {
		printf("Ingrese texto desde stdin:\n");
		while ((buffer = get_next_line(STDIN_FILENO)) != NULL) {
			// Verificar si se asignó memoria correctamente
			if (buffer == NULL) {
				fprintf(stderr, "Fallo al asignar memoria para el buffer\n");
				break;
			}

			// Procesar la línea leída
			printf("RECIBIDO: %s\n", buffer);

			// Liberar la memoria asignada a la línea
			free(buffer);
		}
	}
	else {
		fprintf(stderr, "Uso: %s [archivo1] [archivo2] ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	return 0;
} */

//PRUEBA DE LECTURA DE UN FD DEL CUAL NO ES POSIBLE LA LECTURA
/* int main(int argc, char *argv[])
{
	char *buffer;

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

	// Intentar leer de un descriptor de archivo arbitrario
	int invalid_fd = 42;
	printf("Intentando leer de un fd arbitrario (%d):\n", invalid_fd);
	buffer = get_next_line(invalid_fd);

	if (buffer == NULL) {
		printf("gnl devolvió NULL para el fd arbitrario %d, como esperaba\n",
			invalid_fd);
	} else {
		printf("gnl devolvió algo inesperado para el fd arbitrario %d.\n",
			invalid_fd);
		free(buffer);
	}

	// Cerrar el descriptor de archivo
	if (close(fd) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	return 0;
} */
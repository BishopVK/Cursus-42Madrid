/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_gnl9_FINAL.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:33:09 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/20 15:31:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_and_update_result(char **result, char *line)
{
	char	*tmp;
	char	*newline_ptr;

	ft_strlcpy(line, *result, (ft_strchr(*result, '\n') - *result) + 2);
	tmp = *result;
	newline_ptr = ft_strchr(*result, '\n');
	if (newline_ptr)
		*result = ft_strdup(newline_ptr + 1);
	else
		*result = ft_strdup("");
	free(tmp);
	return (line);
}

static char	*process_result(char **result)
{
	char	*line;

	if (ft_strchr(*result, '\n'))
	{
		line = (char *)malloc(strchr(*result, '\n') - *result + 2);
		line = get_line_and_update_result(result, line);
	}
	else
	{
		line = (char *)malloc(ft_strlen(*result) + 1);
		if (line)
		{
			ft_strlcpy(line, *result, ft_strlen(*result) + 1);
			free(*result);
			*result = NULL;
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
	static char	*result;
	char		*line;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!result)
		result = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read_file(fd, &result, buffer);
	free(buffer);
	if (bytes_read <= 0 && ft_strlen(result) == 0)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line = process_result(&result);
	return (line);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=100
// get_next_line.c get_next_line_utils.c -fsanitize=address -static-libsan
// ./a.out txt/texto.txt

//LECTURA DE FICHERO O DE STDIN
int	main(int argc, char *argv[])
{
	char *buffer;

	// Leer desde archivo si se proporciona un argumento en la línea de comandos
	if (argc == 2)
	{
		// Abrir el archivo para lectura
		int fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}

		// Llamar a la función para leer el contenido del archivo
		while ((buffer = get_next_line(fd)) != NULL)
		{
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

		// Cerrar el descriptor de archivo
		if (close(fd) == -1)
		{
			perror("close");
			exit(EXIT_FAILURE);
		}
	}
	// Leer desde stdin si no se proporcionan argumentos en la línea de comandos
	else if (argc == 1)
	{
		while ((buffer = get_next_line(STDIN_FILENO)) != NULL)
		{
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
	}
	else
	{
		fprintf(stderr, "Uso: %s [nombre_del_archivo]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	return 0;
}

//LECTURA DE FICHERO
/* int	main(int argc, char *argv[])
{
	char	*buffer;

	if (argc != 2)
	{
		fprintf(stderr, "Uso: %s <nombre_del_archivo>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Abrir el archivo para lectura
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	// Llamar a la función para leer el contenido del archivo
	while ((buffer = get_next_line(fd)) != NULL)
	{
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

	// Liberar la memoria asignada a buffer
	//free(buffer);

	// Cerrar el descriptor de archivo
	if (close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}

	return (0);
} */

/* void test_gnl(int fd, const char *expected) {
    char *line = get_next_line(fd);
    if (line == NULL && expected == NULL) {
        printf("Test passed: expected NULL\n");
    } else if (line != NULL && expected != NULL && strcmp(line, expected) == 0) {
        printf("Test passed: %s\n", expected);
    } else {
        printf("Test failed: expected '%s', got '%s'\n", expected, line);
    }
    free(line);
}

int main() {
    char *name = "txt/read_error.txt";
    int fd = open(name, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    test_gnl(fd, "aaaaaaaaaa\n");
    test_gnl(fd, "bbbbbbbbbb\n");

    // Simulate read error
    char *temp;
    do {
        temp = get_next_line(fd);
        free(temp);
    } while (temp != NULL);

    test_gnl(fd, NULL);

    close(fd);
    fd = open(name, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    test_gnl(fd, "aaaaaaaaaa\n");
    test_gnl(fd, "bbbbbbbbbb\n");
    test_gnl(fd, "cccccccccc\n");
    test_gnl(fd, "dddddddddd\n");
    test_gnl(fd, NULL);

    close(fd);

    return 0;
} */
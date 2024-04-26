/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:57:34 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/24 12:57:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int here_doc(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Uso: %s here_doc\n", argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "here_doc") != 0) {
		printf("El primer argumento debe ser \"here_doc\"\n");
		return 1;
	}

	char buffer[1024];
	ssize_t bytes_read;
	while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
		if (bytes_read == -1) {
			perror("Error al leer de stdin");
			return 1;
		}
		if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
			perror("Error al escribir en stdout");
			return 1;
		}
		if (strcmp(buffer, "EOF\n") == 0) {
			break;
		}
	}

	return 0;
}
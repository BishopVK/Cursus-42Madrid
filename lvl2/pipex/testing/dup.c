/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:33:39 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/09 21:33:39 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
	int fd1, fd2;

	// Abre un archivo para lectura
	fd1 = open("access.txt", O_RDONLY);
	if (fd1 == -1) {
		perror("Error al abrir el archivo");
		return 1;
	}

	// Duplica el descriptor de archivo
	fd2 = dup(fd1);
	if (fd2 == -1) {
		perror("Error al duplicar el descriptor de archivo");
		return 1;
	}

	// Imprime los descriptores de archivo
	printf("fd1 = %d, fd2 = %d\n", fd1, fd2);

	// Cierra los descriptores de archivo
	close(fd1);
	close(fd2);

	return 0;
}

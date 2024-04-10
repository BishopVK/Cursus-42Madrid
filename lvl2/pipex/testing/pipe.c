/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:10:01 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/10 09:10:01 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// En el lenguaje de programación C, la función pipe() se utiliza para
// crear un par de descriptores de archivo (file descriptors) que están
// conectados entre sí, donde el extremo de escritura de uno está conectado
// al extremo de lectura del otro. Esto es útil cuando se desea comunicar datos entre dos procesos.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd[2]; // Arreglo para los descriptores de archivo

	if (pipe(fd) == -1)
	{ // Crear la tubería
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork(); // Crear un proceso hijo

	if (pid == -1)
	{ // Comprobar errores al crear el proceso hijo
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{ // Código del proceso hijo
		close(fd[0]); // Cerrar el extremo de lectura del proceso hijo

		// Escribir en el extremo de escritura de la tubería
		char message[] = "Hola desde el hijo";
		write(fd[1], message, sizeof(message));
		close(fd[1]); // Cerrar el extremo de escritura después de escribir

		exit(EXIT_SUCCESS);
	}
	else
	{ // Código del proceso padre
		close(fd[1]); // Cerrar el extremo de escritura del proceso padre

		// Leer desde el extremo de lectura de la tubería
		char buffer[100];
		read(fd[0], buffer, sizeof(buffer));
		printf("Mensaje recibido en el padre: %s\n", buffer);
		close(fd[0]); // Cerrar el extremo de lectura después de leer

		exit(EXIT_SUCCESS);
	}

	return 0;
}

// Este programa crea una tubería utilizando pipe(), luego crea un proceso hijo utilizando
// fork(). El proceso hijo escribe un mensaje en el extremo de escritura de la tubería, y el proceso
// padre lee este mensaje desde el extremo de lectura de la tubería. Después de leer o escribir en la
// tubería, es importante cerrar los descriptores de archivo asociados para evitar posibles
// problemas de manipulación de archivos.
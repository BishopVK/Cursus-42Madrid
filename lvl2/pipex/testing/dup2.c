/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:36:34 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/09 21:36:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Las funciones dup() y dup2() en C son utilizadas para duplicar descriptores de archivo.
// Estas funciones son útiles en situaciones donde necesitas redirigir la entrada,
// salida o error estándar de un proceso, o cuando necesitas duplicar un descriptor
// de archivo para usarlo en múltiples lugares.

// dup2(int oldfd, int newfd): Esta función duplica el descriptor de archivo oldfd a newfd.
// Si newfd ya estaba abierto, primero se cierra. Si oldfd y newfd son iguales,
// dup2() devuelve newfd sin cerrar oldfd.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int fd;
	// Abre un archivo para escribir (si no existe, lo crea; si existe, trunca su contenido)
	fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return 1;
	}

	// Redirige stdout al archivo abierto
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error al redirigir stdout");
		return 1;
	}

	// Ahora, cualquier salida que se enviaría a stdout se escribirá en "salida.txt"

	// Imprime algo, que se escribirá en "salida.txt" en lugar de en la consola
	printf("¡Hola, mundo!\n");

	// Cierra el descriptor de archivo duplicado (no es necesario cerrar STDOUT_FILENO)
	close(fd);

	return 0;
}

// Este programa redirige la salida estándar (stdout) al archivo "salida.txt".
// Después de redirigir la salida estándar, cualquier cosa que normalmente se escribiría
// en la consola (a través de printf(), por ejemplo) se escribirá en el archivo "salida.txt" en su lugar.

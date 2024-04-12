/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:03:47 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/09 21:03:47 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// perror es una función en C que se utiliza para imprimir un mensaje de error
// seguido de una descripción del error correspondiente al valor de errno actual.

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	FILE *fp;

	// Intenta abrir un archivo que no existe para provocar un error
	fp = fopen("archivo_no_existente.txt", "r");
	if (fp == NULL) {
		// Si fopen devuelve NULL, indica un error. perror imprimirá un mensaje
		// de error seguido de una descripción del error correspondiente.
		perror("Error al abrir el archivo");
		// También puedes imprimir tu propio mensaje de error personalizado
		printf("Error al abrir el archivo: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	fclose(fp);
	return 0;
}

// En este ejemplo, perror se utiliza después de una llamada a fopen,
// que intenta abrir un archivo que no existe. Si fopen devuelve NULL,
// perror imprime un mensaje de error con la descripción del error correspondiente
// al valor de errno actual. En este caso, el mensaje impreso sería algo
// como "Error al abrir el archivo: No such file or directory".

// static int my_func(int x) {
// 	if (x > 100)
// 	{
// 		errno = 35;
// 		return (1);
// 	}
// 	errno = 0;
// 	return (0);
// }

// int main() {
// 	my_func(14);
// 	perror("Error con 14");

// 	my_func(214);
// 	perror("Error con 214");

// 	return (1);
// }
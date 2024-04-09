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

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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
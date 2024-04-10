/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:10:11 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/09 21:10:11 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La función access() en C se utiliza para verificar los permisos de acceso a un
// archivo o directorio. Puedes usarla para determinar si un archivo o directorio
// existe y si tienes permiso para realizar ciertas operaciones sobre él,
// como leer, escribir o ejecutar.

#include <stdio.h>
#include <unistd.h>

int main() {
	char *filename = "access.txt";
	
	// Verificar si el archivo existe
	if (access(filename, F_OK) != -1) {
		printf("El archivo existe.\n");
	} else {
		printf("El archivo no existe.\n");
	}

	// Verificar permisos de lectura
	if (access(filename, R_OK) != -1) {
		printf("Tienes permisos de lectura para el archivo.\n");
	} else {
		printf("No tienes permisos de lectura para el archivo.\n");
	}

	// Verificar permisos de escritura
	if (access(filename, W_OK) != -1) {
		printf("Tienes permisos de escritura para el archivo.\n");
	} else {
		printf("No tienes permisos de escritura para el archivo.\n");
	}

	// Verificar permisos de ejecución
	if (access(filename, X_OK) != -1) {
		printf("Tienes permisos de ejecución para el archivo.\n");
	} else {
		printf("No tienes permisos de ejecución para el archivo.\n");
	}

	return 0;
}

// Este programa verificará la existencia del archivo "access.txt" y luego
// verificará si tienes permisos de lectura, escritura y ejecución para ese archivo.
// Asegúrate de incluir #include <unistd.h> para utilizar la función access().
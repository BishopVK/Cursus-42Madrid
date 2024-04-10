/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:13:42 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/10 09:13:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La función unlink() en C se utiliza para eliminar un archivo existente del sistema de archivos.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char filename[] = "unlink.txt";

	// Primero, intentamos eliminar el archivo
	if (unlink(filename) == 0)
	{
		printf("El archivo \"%s\" se eliminó correctamente.\n", filename);
	}
	else
	{
		perror("Error al eliminar el archivo");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

// En este ejemplo:

// 1. Incluimos las cabeceras stdio.h y stdlib.h para usar funciones
// de entrada/salida estándar y para el manejo de errores, respectivamente.

// 2. Declaramos una variable filename que contiene el nombre del archivo que queremos eliminar.

// 3. Llamamos a la función unlink() pasando como argumento el nombre del archivo que queremos eliminar.

// 4. Verificamos si unlink() se ejecutó correctamente. Si lo hizo, imprimimos un mensaje
// indicando que el archivo se eliminó correctamente. De lo contrario, imprimimos un mensaje
// de error utilizando la función perror() y salimos del programa con un código de error.

// Es importante tener en cuenta que unlink() solo elimina el enlace al archivo desde el sistema de archivos, no lo destruye completamente. Si hay otros enlaces al mismo archivo, o si el archivo está abierto por algún proceso, el espacio en disco asociado al archivo no se liberará hasta que todos los enlaces al archivo sean eliminados y todos los descriptores de archivo asociados al archivo sean cerrados.
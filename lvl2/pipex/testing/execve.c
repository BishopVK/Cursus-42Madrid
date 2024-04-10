/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:42:54 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/09 21:42:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La función execve() en C se utiliza para ejecutar
// un programa especificado por su ruta de archivo.

#include <stdio.h>
#include <unistd.h>

int main() {
	// Definir el arreglo de argumentos que se pasarán al programa ejecutable
	char *args[] = {"/bin/ls", "-l", NULL};
	
	// Definir el arreglo de variables de entorno (opcional)
	char *env[] = {NULL};
	
	// Llamar a execve() para ejecutar el programa
	execve(args[0], args, env);
	
	// Si execve() retorna, significa que hubo un error
	perror("execve");
	return 1;
}

// Explicación:

// 1. Incluimos las bibliotecas necesarias:
// 	- stdio.h para la función perror().
// 	- unistd.h para la función execve().

// 2. Definimos un arreglo args[] que contiene la ruta del programa
//    a ejecutar y sus argumentos. El último elemento de este arreglo debe
//    ser NULL para indicar el final de la lista de argumentos.

// 3. Opcionalmente, se puede definir un arreglo env[] que contenga
//    las variables de entorno que se deseen pasar al programa ejecutable.
//    En este caso, no estamos pasando ninguna variable de entorno adicional,
//    por lo que hemos definido un arreglo vacío.

// 4. Llamamos a execve() con tres argumentos:
// 	- La ruta del programa a ejecutar
// 	- El arreglo de argumentos
// 	- El arreglo de variables de entorno

// 5. Si execve() retorna, significa que ha habido un error.
//    En ese caso, imprimimos un mensaje de error utilizando perror().

// Es importante tener en cuenta que después de llamar a execve(),el proceso
// actual será reemplazado por el programa especificado, y el control nunca
// volverá a la función main() a menos que haya un error en la ejecución del programa.
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
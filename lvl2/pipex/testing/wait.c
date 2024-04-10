/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:18:35 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/10 09:18:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Las funciones wait() y waitpid() en C son utilizadas para esperar que un proceso hijo termine su ejecución.

// La función wait() suspende la ejecución del proceso actual hasta
// que uno de sus procesos hijos termine o sea interrumpido por una señal.

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		// Proceso hijo
		printf("Soy el proceso hijo\n");
		exit(0);
	}
	else if (pid > 0)
	{
		// Proceso padre
		printf("Esperando al proceso hijo...\n");
		wait(&status);
		printf("Proceso hijo terminado\n");
	}
	else
	{
		// Error en fork()
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return 0;
}

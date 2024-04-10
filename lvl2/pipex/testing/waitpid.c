/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:21:18 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/10 09:21:18 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La función waitpid() permite esperar por un proceso hijo específico o
// cualquier proceso hijo, proporcionando más control sobre qué proceso esperar.

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
		sleep(2); // Simulando un proceso que dura 2 segundos
		exit(0);
	}
	else if (pid > 0)
	{
		// Proceso padre
		printf("Esperando al proceso hijo...\n");
		waitpid(pid, &status, 0); // Esperar específicamente al proceso hijo con PID pid
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

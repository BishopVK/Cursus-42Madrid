/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:49:57 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/10 08:49:57 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// La función fork() en C se utiliza para crear un nuevo proceso, que es una copia
// exacta del proceso que la llama (el proceso padre). La función fork() devuelve
// diferentes valores para el proceso padre y el proceso hijo, lo que permite al
// programa distinguir entre los dos.

#include <stdio.h>
#include <unistd.h>

int	main()
{
	pid_t pid;

	pid = fork(); // Se crea un nuevo proceso

	if (pid < 0)
	{
		// Error al crear el proceso hijo
		fprintf(stderr, "Error al crear el proceso hijo\n");
		return 1;
	}
	else if (pid == 0)
	{
		// Este es el proceso hijo
		printf("Hola, soy el proceso hijo (PID: %d)\n", getpid());
	}
	else
	{
		// Este es el proceso padre
		printf("Hola, soy el proceso padre (PID: %d)\n", getpid());
	}

	return 0;
}

// En este ejemplo, el proceso padre crea un nuevo proceso hijo llamando a fork().
// Después de llamar a fork(), el proceso hijo y el proceso padre continúan ejecutándose
// a partir de ese punto, y el valor devuelto por fork() les permite saber cuál es cuál.

//	- Si fork() devuelve un valor negativo, indica que ha ocurrido un error al crear el proceso hijo.
//	- Si fork() devuelve 0, eso significa que el proceso actual es el proceso hijo.
//	- Si fork() devuelve un número mayor que 0, entonces ese es el ID del proceso hijo para el proceso padre.

// Es importante tener en cuenta que después de llamar a fork(), ambos procesos
// continuarán ejecutando el código que sigue a la llamada fork(), por lo que debes
// tener cuidado con las instrucciones que siguen al fork si deseas que sean diferentes para el padre y el hijo.
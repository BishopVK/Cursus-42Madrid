/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:46:12 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/23 22:44:55 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

// Prototipo:	int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

// Descripción:	Crea un nuevo hilo que ejecuta la función start_routine con el argumento arg.
//				El identificador del hilo creado se almacena en thread.

#define NUM_THREADS 5

int	contador = 0; //Variable global

void	*funcion_hilos(void *arg)
{
	int	i;
	for (i = 0; i < 100000; i++){
		contador++;
	}
}

int	main(void)
{
	pthread_t	threads[NUM_THREADS];
	int	i;

	for (i = 0; i < NUM_THREADS; i++){
		pthread_create(&threads[i], NULL, funcion_hilos, NULL);
	}

	for (i = 0; i < NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
	}

	printf("El valor final del contador es: %d\n", contador);
	
	return (0);
}

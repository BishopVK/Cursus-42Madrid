/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_race.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:46:12 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/24 09:21:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

//---pthread_create---
// Prototipo:	int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
// Descripción:	Crea un nuevo hilo que ejecuta la función start_routine con el argumento arg.
//				El identificador del hilo creado se almacena en thread.

// ----------------------------

//---pthread_join---
// Prototipo:	int pthread_join(pthread_t thread, void **retval);
// Descripción:	Espera a que el hilo identificado por thread termine.
//				Si retval no es NULL, se almacena el valor de retorno del hilo en la ubicación señalada por retval.

// ----------------------------

//---pthread_detach---
// Prototipo:	int pthread_detach(pthread_t thread);
// Descripción:	Desvincula el hilo identificado por thread, permitiendo que sus recursos sean liberados automáticamente cuando el hilo termine.

#define NUM_THREADS 5

int	contador = 0; // Variable global

void	*funcion_hilos(void *arg)
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		contador++;
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	threads[NUM_THREADS];
	int			i;

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&threads[i], NULL, funcion_hilos, NULL);
		i++;
	}

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	printf("El valor final del contador es: %d\n", contador);

	return (0);
}

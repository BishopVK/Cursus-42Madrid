/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create_V2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:46:12 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/24 09:35:46 by danjimen         ###   ########.fr       */
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

// ----------------------------

//---pthread_mutex_init---
// Prototipo:	int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
// Descripción:	Inicializa el mutex apuntado por mutex con los atributos especificados por attr. Si attr es NULL, se utilizan los atributos por defecto.

// ----------------------------

//---pthread_mutex_destroy---
// Prototipo:	int pthread_mutex_destroy(pthread_mutex_t *mutex);
// Descripción:	Destruye el mutex apuntado por mutex. El comportamiento es indefinido si hay hilos bloqueados en el mutex cuando se destruye.

// ----------------------------

//---pthread_mutex_lock---
// Prototipo:	int pthread_mutex_lock(pthread_mutex_t *mutex);
// Descripción:	Bloquea el mutex apuntado por mutex. Si el mutex ya está bloqueado por otro hilo, el hilo que llama se bloquea hasta que el mutex se desbloquee.

// ----------------------------

//---pthread_mutex_unlock---
// Prototipo:	int pthread_mutex_unlock(pthread_mutex_t *mutex);
// Descripción:	Desbloquea el mutex apuntado por mutex. Si hay otros hilos esperando el mutex, uno de ellos se desbloquea y adquiere el mutex.

#define NUM_THREADS 5

int				contador = 0; // Variable global
pthread_mutex_t	mutex;

void	*funcion_hilos(void *arg)
{
	int	i;
	int	*thread_number;

	i = 0;
	while (i < 100000)
	{
		// Los hilos se quedan aquí hasta que otro hilo salga de la zona crítica

		// Bloqueamos el acceso a varios hilos a la sección crítica
		pthread_mutex_lock(&mutex);
		thread_number = (int *)arg;
		contador++;
		printf("Soy el hilo %d\n", *thread_number);
		// Desbloqueamos el acceso a varios hilos a la sección crítica
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	threads[NUM_THREADS];
	int			i;

	// Iniciamos el mutex
	pthread_mutex_init(&mutex, NULL);

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&threads[i], NULL, funcion_hilos, &i);
		i++;
	}

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	printf("El valor final del contador es: %d\n", contador);

	// Destruimos el mutex cuando todos los hilos terminen
	pthread_mutex_destroy(&mutex);

	return (0);
}

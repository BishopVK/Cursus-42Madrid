/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/26 08:42:05 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*funcion_hilos(void *arg)
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		// Los hilos se quedan aquí hasta que otro hilo salga de la zona crítica

		// Bloqueamos el acceso a varios hilos a la sección crítica
		pthread_mutex_lock(&mutex);
		contador++;
		// Desbloqueamos el acceso a varios hilos a la sección crítica
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	threads_nbr[NUM_THREADS];
	t_threads	threads;
	int			i;

	memset(&threads, 0, sizeof(t_threads));

	// Iniciamos el mutex
	pthread_mutex_init(&threads.mutex, NULL);

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&threads_nbr[i], NULL, funcion_hilos, &threads);
		i++;
	}

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads_nbr[i], NULL);
		i++;
	}

	printf("El valor final del contador es: %d\n", threads.counter);

	// Destruimos el mutex cuando todos los hilos terminen
	pthread_mutex_destroy(&threads.mutex);

	return (0);
}

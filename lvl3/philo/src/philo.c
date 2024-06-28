/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/28 14:37:55 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* void	*funcion_hilos(void *arg)
{
	int	i;
	t_threads *threads;

	i = 0;
	threads = (t_threads *)arg;
	printf("Soy el hilo %d\n", threads->philo_nbr);
	while (i < 100000)
	{
		// Los hilos se quedan aquí hasta que otro hilo salga de la zona crítica

		// Bloqueamos el acceso a varios hilos a la sección crítica
		pthread_mutex_lock(&threads->mutex);
		threads->counter++;
		// Desbloqueamos el acceso a varios hilos a la sección crítica
		pthread_mutex_unlock(&threads->mutex);
		i++;
	}
	return (NULL);
} */

int	main(int argc, char **argv)
{
	t_table	table;

	if (validate_args(argc, argv, &table) != 0)
		return (1);
	printf("nbr_philosophers == %i\n", table.nbr_philosophers);
	printf("time_to_die == %i\n", table.time_to_die);
	printf("time_to_eat == %i\n", table.time_to_eat);
	printf("time_to_sleep == %i\n", table.time_to_sleep);
	printf("nbr_must_eat == %i\n", table.nbr_must_eat);

	// Comprobar leaks de liberación de memoria antes de inicializar los hilos

	return (0);
}

/* int	main(void)
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
		threads.philo_nbr = i;
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
} */

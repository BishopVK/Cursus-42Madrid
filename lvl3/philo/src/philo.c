/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/27 15:40:58 by danjimen         ###   ########.fr       */
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

t_table	parse_args(int argc, char **argv)
{
	t_table	table;

	table.time_to_die = argv[1];
	table.time_to_eat = argv[2];
	table.time_to_sleep = argv[3];
	if (argc == 6)
		table.nbr_must_eat = argv[4];
	else
		table.nbr_must_eat = -1;
	return (table);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc >= 5 && argc <= 6)
		table = parse_args(argc, argv);
	else
	{
		printf("Correct use: ./philo time_to_die time_to_eat time_to_sleep");
		printf("[number_of_times_each_philosopher_must_eat]\n");
	}
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

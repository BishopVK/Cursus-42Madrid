/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/02 08:18:23 by danjimen         ###   ########.fr       */
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

static void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->nbr_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->end_mutex);
	free(table->forks);
	free(table->philos);
}

long	get_current_time(void)
{
	struct timeval	time;
	long			time_miliseconds;

	gettimeofday(&time, NULL);
	time_miliseconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_miliseconds);
}

static void	initialize_structs(t_table *table)
{
	int	i;
	struct timeval	time;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
	table->philos = malloc(sizeof(t_philosopher) * table->nbr_philos);
	table->loop_end = 0;
	gettimeofday(&time, NULL);
	table->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_init(&table->end_mutex, NULL);
	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal_time = get_current_time();
		table->philos[i].table = table;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	// Parseo
	if (validate_args(argc, argv, &table) != 0)
		return (1);

	// Inicialización de estructuras
	initialize_structs(&table);

	// Crear hilos para los filósofos
	i = 0;
	while (i < table.nbr_philos)
	{
		pthread_create(&table.philos[i].thread, NULL, philo_routine, &table.philos[i]);
		i++;
	}

	// Esperar a que los hilos terminen
	i = 0;
	while (i < table.nbr_philos)
	{
		pthread_join(table.philos[i].thread, NULL);
		i++;
	}

	// Liberar al final
	cleanup(&table);
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

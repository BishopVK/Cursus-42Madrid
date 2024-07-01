/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/01 10:05:44 by danjimen         ###   ########.fr       */
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

/*
typedef struct s_philosopher
{
	int			id;
	pthread_t	thread;
	int			meals_eaten;
	long		last_meal_time;
}	t_philosopher;
*/

static void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->nbr_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
	free(table->philos);
}

static void	initialize_structs(t_table *table)
{
	int	i;
	struct timeval	current_time;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
	table->philos = malloc(sizeof(t_philosopher) * table->nbr_philos);
	i = 0;
	while(i < table->nbr_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		gettimeofday(&current_time, NULL);
		table->philos[i].last_meal_time = current_time.tv_usec;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;
	int	i;

	// Parseo
	if (validate_args(argc, argv, &table) != 0)
		return (1);
	printf("nbr_philos == %i\n", table.nbr_philos);
	printf("time_to_die == %i\n", table.time_to_die);
	printf("time_to_eat == %i\n", table.time_to_eat);
	printf("time_to_sleep == %i\n", table.time_to_sleep);
	printf("nbr_must_eat == %i\n", table.nbr_must_eat);

	// Inicialización de estructuras
	initialize_structs(&table);
	// Comprobar leaks de liberación de memoria antes de inicializar los hilos

	//Bucle de comprobación
	i = 0;
	while(i < table.nbr_philos)
	{
		printf("table.philos[i].id == %i\n", table.philos[i].id);
		printf("table.philos[i].meals_eaten == %i\n", table.philos[i].meals_eaten);
		printf("table.philos[i].last_meal_time == %li\n", table.philos[i].last_meal_time);
		i++;
	}

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

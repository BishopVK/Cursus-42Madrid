/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/02 23:00:03 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
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
	pthread_mutex_destroy(&table->global_mutex);
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
	pthread_mutex_init(&table->global_mutex, NULL);
	table->even_delay = table->time_to_eat;
	if (table->time_to_eat > table->time_to_sleep)
		table->even_delay = table->time_to_sleep;
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

/*
1 800 200 200 (muere)
5 800 200 200 (viven)
5 800 200 200 7 (viven y cada uno come 7 veces)
4 410 200 200 (viven)
4 310 200 100 (mueren)

3 310 103 103 (tienen que vivir)
3 310 104 104 (tienen que morir)
181 400 200 200 (mueren)
*/

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

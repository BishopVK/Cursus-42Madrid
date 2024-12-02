/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/16 18:44:17 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
} */

/* void	ft_usleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
} */

/* long long	ft_calc_time(void)
{
	struct timeval	tv;
	long long	time_now;

	gettimeofday(&tv, NULL);
	time_now = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (time_now);
} */

/* void	ft_usleep(int time)
{
	long long	old_time;

	old_time = ft_calc_time();
	while ((ft_calc_time() - old_time) < time)
		usleep(400);
} */

long	get_current_time(void)
{
	struct timeval	current;
	long			current_miliseconds;

	gettimeofday(&current, NULL);
	current_miliseconds = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (current_miliseconds);
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < time / 1000)
	{
		/* printf("DB: Entré\n");
		printf("DB: get_instant() = %zu\n", get_instant());
		printf("DB: start = %zu\n", start);
		printf("DB: get_instant() - start = %zu\n", get_instant() - start);
		printf("DB: time = %zu\n", time / 1000); */
		usleep(200);
	}
}

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

static void	initialize_structs(t_table *table)
{
	int	i;
	struct timeval	time;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
	table->philos = malloc(sizeof(t_philosopher) * table->nbr_philos);
	table->loop_end = false;
	table->total_meals = 0;
	gettimeofday(&time, NULL);
	table->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_init(&table->end_mutex, NULL);
	pthread_mutex_init(&table->global_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
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
		table->philos[i].im_die = false;
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

	// Crear hilo para el árbitro
	pthread_create(&table.referee, NULL, referee_routine, &table);

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
	pthread_join(table.referee, NULL);
	
	// Liberar al final
	cleanup(&table);
	return (0);
}

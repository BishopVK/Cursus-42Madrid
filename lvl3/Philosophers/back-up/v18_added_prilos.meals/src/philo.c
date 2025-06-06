/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/21 12:22:14 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->end_mutex);
	pthread_mutex_destroy(&table->global_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	free(table->forks);
	free(table->philos);
}

static void	initialize_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		table->philos[i].id = i + 1;
		table->philos[i].last_meal_time = get_current_time();
		table->philos[i].death_date = table->time_to_die;
		table->philos[i].table = table;
		i++;
	}
}

static void	initialize_structs(t_table *table)
{
	struct timeval	time;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
	table->philos = malloc(sizeof(t_philosopher) * table->nbr_philos);
	table->loop_end = false;
	table->total_meals = 0;
	table->philos_meals = 0;
	table->im_die = 0;
	gettimeofday(&time, NULL);
	table->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_init(&table->end_mutex, NULL);
	pthread_mutex_init(&table->global_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	table->even_delay = table->time_to_eat;
	if (table->time_to_eat > table->time_to_sleep)
		table->even_delay = table->time_to_sleep;
	initialize_philos(table);
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	if (validate_args(argc, argv, &table) != 0)
		return (1);
	initialize_structs(&table);
	pthread_create(&table.referee, NULL, referee_routine, &table);
	i = 0;
	while (i < table.nbr_philos)
	{
		pthread_create(&table.philos[i].thread, NULL,
			philo_routine, &table.philos[i]);
		i++;
	}
	pthread_join(table.referee, NULL);
	i = 0;
	while (i < table.nbr_philos)
	{
		pthread_join(table.philos[i].thread, NULL);
		i++;
	}
	cleanup(&table);
	return (0);
}

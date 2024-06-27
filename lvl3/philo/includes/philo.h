/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:52:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/27 15:31:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pthread_create, pthread_join, pthread_detach, pthread_mutex_init
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
#include <pthread.h>

// printf
#include <stdio.h>

// memset
#include <string.h>

// malloc, free
#include <stdlib.h>

// write, usleep
#include <unistd.h>

// gettimeofday
#include <sys/time.h>

#define NUM_THREADS 5

/* typedef struct s_threads
{
	int				counter;
	int				philo_nbr;
	pthread_mutex_t	mutex;
}	t_threads; */

typedef struct s_philosopher
{
	int			id;
	pthread_t	thread;
	int			meals_eaten;
	long		last_meal_time;
}	t_philosopher;

typedef struct s_table
{
	int					nbr_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_must_eat;
	pthread_mutex_t		*forks; // Array de mutexes
	struct Philosopher	*philosophers;
}	t_table;

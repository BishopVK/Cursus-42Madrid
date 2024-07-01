/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:52:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/01 19:50:00 by danjimen         ###   ########.fr       */
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

// INT_MAX, INT_MIN
#include <limits.h>

#define NUM_THREADS 5

/* typedef struct s_threads
{
	int				counter;
	int				philo_nbr;
	pthread_mutex_t	mutex;
}	t_threads; */

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	int				meals_eaten;
	long			last_meal_time;
	struct s_table	*table;
}	t_philosopher;

typedef struct s_table
{
	int					nbr_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_must_eat;
	pthread_mutex_t		*forks; // Array de mutexes
	t_philosopher		*philos;
}	t_table;

/*_____           _        _   _                  
 |  __ \         | |      | | (_)                 
 | |__) | __ ___ | |_ ___ | |_ _ _ __   ___  ___  
 |  ___/ '__/ _ \| __/ _ \| __| | '_ \ / _ \/ __| 
 | |   | | | (_) | || (_) | |_| | |_) |  __/\__ \ 
 |_|   |_|  \___/ \__\___/ \__|_| .__/ \___||___/ 
                                | |               
                                |_|             */

//////////////////////////////////////////////////////
//					FUNCTIONS						//
//////////////////////////////////////////////////////
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);

//////////////////////////////////////////////////////
//						PARSE.C						//
//////////////////////////////////////////////////////
long	get_current_time(void);
int		validate_args(int argc, char **argv, t_table *table);

//////////////////////////////////////////////////////
//					ROUTINE.C						//
//////////////////////////////////////////////////////
void	print_action(int id, char *action);
void	*philo_routine(void *arg);

//////////////////////////////////////////////////////
//					ACTIONS.C						//
//////////////////////////////////////////////////////
void	think(t_philosopher *philo);
void	eat(t_philosopher *philo);
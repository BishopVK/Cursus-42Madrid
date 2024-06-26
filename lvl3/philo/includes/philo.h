/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:52:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/26 10:52:32 by danjimen         ###   ########.fr       */
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

typedef struct s_threads
{
	int				counter;
	int				philo_nbr;
	pthread_mutex_t	mutex;
}	t_threads;

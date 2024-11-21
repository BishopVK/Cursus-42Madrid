/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:52:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 21:18:31 by danjimen         ###   ########.fr       */
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

#define OK 0
#define ERR 1

typedef enum s_bool
{
	false,
	true,
}	t_bool;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	long			last_meal_time;
	long			death_date;
	struct s_table	*table;
}	t_philosopher;

typedef struct s_table
{
	int					nbr_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_must_eat;
	int					total_meals;
	pthread_mutex_t		*forks;
	t_philosopher		*philos;
	int					loop_end;
	pthread_mutex_t		end_mutex;
	long				start_time;
	pthread_mutex_t		global_mutex;
	int					even_delay;
	pthread_t			referee;
	int					im_die;
	pthread_mutex_t		print_mutex;
}	t_table;

/*_____           _        _                         
 |  __ \         | |      | |                        
 | |__) | __ ___ | |_ ___ | |_ _   _ _ __   ___  ___ 
 |  ___/ '__/ _ \| __/ _ \| __| | | | '_ \ / _ \/ __|
 | |   | | | (_) | || (_) | |_| |_| | |_) |  __/\__ \
 |_|   |_|  \___/ \__\___/ \__|\__, | .__/ \___||___/
                                __/ | |              
                               |___/|_|            */

//////////////////////////////////////////////////////
//						PHILO.C						//
//////////////////////////////////////////////////////
long	get_current_time(void);
void	ft_usleep(size_t time);

//////////////////////////////////////////////////////
//						PARSE.C						//
//////////////////////////////////////////////////////
int		validate_args(int argc, char **argv, t_table *table);

// ╔═.✵.═════════════════════════════════════════════╗
//					ROUTINE FOLDER
// ╚═════════════════════════════════════════════.✵.═╝
//////////////////////////////////////////////////////
//					PHILO_ROUTINE.C					//
//////////////////////////////////////////////////////
void	*philo_routine(void *arg);

//////////////////////////////////////////////////////
//					REFEREE_ROUTINE.C				//
//////////////////////////////////////////////////////
void	*referee_routine(void *arg);

// ╔═.✵.═════════════════════════════════════════════╗
//					ACTIONS FOLDER
// ╚═════════════════════════════════════════════.✵.═╝
//////////////////////////////////////////////////////
//						THINK.C						//
//////////////////////////////////////////////////////
void	think(t_philosopher *philo);

//////////////////////////////////////////////////////
//						EAT.C						//
//////////////////////////////////////////////////////
void	eat(t_philosopher *philo);
//int		eat(t_philosopher *philo);

//////////////////////////////////////////////////////
//						SLEEP.C						//
//////////////////////////////////////////////////////
void	sleep_philo(t_philosopher *philo, int t_sleep);

//////////////////////////////////////////////////////
//					TAKE_FORKS.C					//
//////////////////////////////////////////////////////
void	take_forks(t_philosopher *philo);

//////////////////////////////////////////////////////
//					LEAVE_FORKS.C					//
//////////////////////////////////////////////////////
void	leave_forks(t_philosopher *philo);

//////////////////////////////////////////////////////
//					PRINT_ACTION.C					//
//////////////////////////////////////////////////////
void	print_action(int id, char *action, t_table *table);

// ╔═.✵.═════════════════════════════════════════════╗
//					FUNCTIONS FOLDER
// ╚═════════════════════════════════════════════.✵.═╝
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
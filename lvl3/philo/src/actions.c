/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/17 22:46:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* void	think(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is thinking", philo->table);
	}
	else
		pthread_mutex_unlock(&philo->table->end_mutex);
} */

void	think(t_philosopher *philo)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	//printf("DB: Entré a pensar!\n");
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == false)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is thinking", philo->table);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		return ;
	}
	if (philo->table->nbr_philos % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	//ft_usleep((t_think * 0.21) * 1000);
	ft_usleep((t_think * 0.1) * 1000);
}

void	eat(t_philosopher *philo)
{
	long	remaining_life_time;
	int		t_eat;

	remaining_life_time = philo->table->time_to_die - (get_current_time() - philo->last_meal_time);
	/* printf("DB: philo->table->time_to_die == %i\n", philo->table->time_to_die);
	printf("DB: get_current_time() == %li\n", get_current_time());
	printf("DB: philo->last_meal_time == %li\n", philo->last_meal_time);
	printf("DB: get_current_time() - philo->last_meal_time == %li\n", get_current_time() - philo->last_meal_time);
	printf("DB: remaining_life_time == %li\n", remaining_life_time); */

	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == false)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is eating", philo->table);
		pthread_mutex_lock(&philo->table->global_mutex);
		philo->table->total_meals++;
		pthread_mutex_unlock(&philo->table->global_mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		return ;
	}
	if (remaining_life_time < philo->table->time_to_eat)
	{
		//printf("DB: remaining_life_time == %li\n", remaining_life_time);
		ft_usleep(remaining_life_time * 1000);
		pthread_mutex_lock(&philo->table->end_mutex);
		philo->table->im_die = true;
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "died", philo->table);
		return ;
	}
	t_eat = 0;
	while (t_eat <= philo->table->time_to_eat)
	{
		pthread_mutex_lock(&philo->table->end_mutex);
		if (philo->table->loop_end == true)
		{
			pthread_mutex_unlock(&philo->table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->end_mutex);
		if (1 > philo->table->time_to_eat - t_eat)
			ft_usleep((philo->table->time_to_eat - t_eat) * 1000);
		else
			ft_usleep(1 * 1000);
		t_eat += 1;
	}
	//ft_usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_lock(&philo->table->global_mutex);
	//philo->table->total_meals++;
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->table->global_mutex);
}

void	sleep_philosopher(t_philosopher *philo)
{
	/* pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == false)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is sleeping", philo->table);
	}
	else
		pthread_mutex_unlock(&philo->table->end_mutex);
	ft_usleep(philo->table->time_to_sleep * 1000); */
	int	t_sleep;

	t_sleep = 0;
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == false)
	{
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "is sleeping", philo->table);
	}
	else
		pthread_mutex_unlock(&philo->table->end_mutex);
	while (t_sleep <= philo->table->time_to_sleep)
	{
		pthread_mutex_lock(&philo->table->end_mutex);
		if (philo->table->loop_end == true)
		{
			pthread_mutex_unlock(&philo->table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->end_mutex);
		if (1 > philo->table->time_to_sleep - t_sleep)
			ft_usleep((philo->table->time_to_sleep - t_sleep) * 1000);
		else
			ft_usleep(1 * 1000);
		t_sleep += 1;
	}
	//ft_usleep(philo->table->time_to_sleep * 1000);
}

/* void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	if (philo->id % 2 == 0)
	{
		while (1)
		{
			pthread_mutex_lock(&philo->table->global_mutex); // Lock the global mutex to check forks availability
			pthread_mutex_lock(&philo->table->forks[left_fork]);
			if (pthread_mutex_lock(&philo->table->forks[right_fork]) == 0)
			{
				pthread_mutex_unlock(&philo->table->global_mutex); // Unlock the global mutex as we have taken both forks
				if (philo->table->loop_end == 0)
					print_action(philo->id, "has taken a fork", philo->table->start_time);
				if (philo->table->loop_end == 0)
					print_action(philo->id, "has taken a fork", philo->table->start_time);
				return ; // Both forks taken, exit the function
			}
			else
			{
				pthread_mutex_unlock(&philo->table->forks[left_fork]); // Release the left fork if right fork is not available
				pthread_mutex_unlock(&philo->table->forks[right_fork]); // Release the left fork if right fork is not available
			}
			pthread_mutex_unlock(&philo->table->global_mutex); // Unlock the global mutex if we couldn't take both forks
			usleep(100);
		}
	}
	else
	{
		while (1)
		{
			pthread_mutex_lock(&philo->table->global_mutex); // Lock the global mutex to check forks availability
			pthread_mutex_lock(&philo->table->forks[right_fork]);
			if (pthread_mutex_lock(&philo->table->forks[left_fork]) == 0)
			{
				pthread_mutex_unlock(&philo->table->global_mutex); // Unlock the global mutex as we have taken both forks
				if (philo->table->loop_end == 0)
					print_action(philo->id, "has taken a fork", philo->table->start_time);
				if (philo->table->loop_end == 0)
					print_action(philo->id, "has taken a fork", philo->table->start_time);
				return ; // Both forks taken, exit the function
			}
			else
			{
				pthread_mutex_unlock(&philo->table->forks[right_fork]); // Release the left fork if right fork is not available
				pthread_mutex_unlock(&philo->table->forks[left_fork]); // Release the left fork if right fork is not available
			}
			pthread_mutex_unlock(&philo->table->global_mutex); // Unlock the global mutex if we couldn't take both forks
			usleep(100);
		}
	}
} */

/* void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[left_fork]);
		if (philo->table->loop_end == 0)
			print_action(philo->id, "has taken a fork", philo->table->start_time);
		pthread_mutex_lock(&philo->table->forks[right_fork]);
		if (philo->table->loop_end == 0)
			print_action(philo->id, "has taken a fork", philo->table->start_time);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[right_fork]);
		if (philo->table->loop_end == 0)
			print_action(philo->id, "has taken a fork", philo->table->start_time);
		pthread_mutex_lock(&philo->table->forks[left_fork]);
		if (philo->table->loop_end == 0)
			print_action(philo->id, "has taken a fork", philo->table->start_time);
	}
} */

static t_bool	one_philo_case(t_philosopher *philo, int left_fork, int right_fork)
{
	if (left_fork == right_fork)
	{
		//printf("DB: Entré en one_philo_case()\n");
		//philo->table->loop_end = true;
		print_action(philo->id, "has taken a fork", philo->table);
		ft_usleep(philo->table->time_to_die * 1000);
		/* if (philo->table->time_to_die < philo->table->time_to_eat)
			ft_usleep(philo->table->time_to_die * 1000);
		else
			ft_usleep(philo->table->time_to_eat * 1000); */
		pthread_mutex_lock(&philo->table->end_mutex);
		philo->table->im_die = true;
		pthread_mutex_unlock(&philo->table->end_mutex);
		print_action(philo->id, "died", philo->table);
		return (true);
	}
	return (false);
}

/* void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	pthread_mutex_lock(&philo->table->forks[left_fork]);
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "has taken a fork", philo->table->start_time);
	pthread_mutex_unlock(&philo->table->end_mutex);
	if (one_philo_case(philo, left_fork, right_fork) == true)
		return ;
	pthread_mutex_lock(&philo->table->forks[right_fork]);
	pthread_mutex_lock(&philo->table->end_mutex);
	if (philo->table->loop_end == 0)
		print_action(philo->id, "has taken a fork", philo->table->start_time);
	pthread_mutex_unlock(&philo->table->end_mutex);
} */

void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;
	//int	loop_ended;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;

	if (one_philo_case(philo, left_fork, right_fork) == true)
		return ;
	// Check loop_end only once to simplify mutex locking
	/* pthread_mutex_lock(&philo->table->end_mutex);
	loop_ended = philo->table->loop_end;
	pthread_mutex_unlock(&philo->table->end_mutex);

	if (loop_ended)
		return ; */

	// Acquire forks in a fixed order based on the philosopher's ID
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[left_fork]);
		print_action(philo->id, "has taken a fork", philo->table);
		pthread_mutex_lock(&philo->table->forks[right_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[right_fork]);
		print_action(philo->id, "has taken a fork", philo->table);
		pthread_mutex_lock(&philo->table->forks[left_fork]);
	}
	print_action(philo->id, "has taken a fork", philo->table);
}

void	leave_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->table->nbr_philos;
	if (philo->table->nbr_philos != 1)
	{
		pthread_mutex_unlock(&philo->table->forks[left_fork]);
		pthread_mutex_unlock(&philo->table->forks[right_fork]);
	}
}
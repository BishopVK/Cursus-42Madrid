/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:00:19 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 08:07:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	validate_args_set(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < 0)
			return (1);
		i++;
	}
	/* if (ft_atol(argv[1]) <= 1)
		return (2); */
	/* if (ft_atol(argv[2]) < 60 || ft_atol(argv[3]) < 60
		|| ft_atol(argv[4]) < 60)
		return (3); */
	return (0);
}

static t_table	parse_args(int argc, char **argv)
{
	t_table	table;

	table.nbr_philos = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table.nbr_must_eat = ft_atoi(argv[5]);
	else
		table.nbr_must_eat = -1;
	return (table);
}

int	validate_args(int argc, char **argv, t_table *table)
{
	if (argc >= 5 && argc <= 6)
	{
		if (validate_args_set(argc, argv) != 0)
		{
			if (validate_args_set(argc, argv) == 1)
				printf("Invalid args type\n");
			/* if (validate_args_set(argc, argv) == 2)
				printf("Minimum of philosophers must be 2\n"); */
			/* if (validate_args_set(argc, argv) == 3)
				printf("Minimum time to die, eat or sleep must be 60\n"); */
			return (1);
		}
		*table = parse_args(argc, argv);
	}
	else
	{
		printf("Correct use: ./philo number_of_philosophers time_to_die");
		printf(" time_to_eat time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	return (0);
}

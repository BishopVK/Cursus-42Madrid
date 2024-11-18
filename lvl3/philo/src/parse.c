/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:00:19 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/18 08:26:49 by danjimen         ###   ########.fr       */
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
	if (ft_atol(argv[1]) < 1)
		return (2);
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
				write(2, "Invalid args type\n", 19);
			if (validate_args_set(argc, argv) == 2)
				write(2, "Minimum of philosophers must be 1\n", 35);
			return (1);
		}
		*table = parse_args(argc, argv);
	}
	else
	{
		write(2, "Correct use: ./philo number_of_philosophers time_to_die", 56);
		write(2, " time_to_eat time_to_sleep", 27);
		write(2, " [number_of_times_each_philosopher_must_eat]\n", 46);
		return (1);
	}
	return (0);
}

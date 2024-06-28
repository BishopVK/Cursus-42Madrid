/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:00:19 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/28 11:07:35 by danjimen         ###   ########.fr       */
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
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

static t_table	parse_args(int argc, char **argv)
{
	t_table	table;

	table.time_to_die = ft_atoi(argv[1]);
	table.time_to_eat = ft_atoi(argv[2]);
	table.time_to_sleep = ft_atoi(argv[3]);
	if (argc == 5)
		table.nbr_must_eat = ft_atoi(argv[4]);
	else
		table.nbr_must_eat = -1;
	return (table);
}

int	validate_args(int argc, char **argv, t_table *table)
{
	if (argc >= 4 && argc <= 5)
	{
		if (validate_args_set(argc, argv) != 0)
		{
			printf("Invalid args type\n");
			return (1);
		}
		*table = parse_args(argc, argv);
	}
	else
	{
		printf("Correct use: ./philo time_to_die time_to_eat time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	return (0);
}
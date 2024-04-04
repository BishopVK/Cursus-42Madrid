/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:04:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/04 19:46:17 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	signs_checker(char *argv)
{
	int	i;

	i = 0;
	if (ft_strlen(&argv[i]) < 2)
	{
		if (ft_isdigit(argv[i]))
			return ;
		else
		{
			ft_printf("Error\n");
			exit(-1);
		}
	}
	while (argv[i + 1] != '\0')
	{
		if ((argv[i] != ' ' && (argv[i + 1] == '+' || argv[i + 1] == '-'))
			|| ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] == ' '))
		{
			ft_printf("Error\n");
			exit(-1);
		}
		i++;
	}
}

int	allowed_chars(char *argv, char *allowed)
{
	int		j;
	int		k;
	int		not_allowed_char;

	j = 0;
	not_allowed_char = 0;
	while (argv[j] != '\0')
	{
		k = 0;
		while (allowed[k] != '\0')
		{
			if (argv[j] != allowed[k])
				not_allowed_char++;
			else
			{
				not_allowed_char = 0;
				break ;
			}
			k++;
		}
		if (not_allowed_char != 0)
			return (not_allowed_char);
		j++;
	}
	return (not_allowed_char);
}

t_stack_node	*split_argvs(char *argv, int *total_strings,
					t_stack_node *new_node, int *out_of_limits)
{
	int				i;
	char			**split;
	int				num_strings;
	long long int	num_not_integer;

	if (argv[0] == '\0')
		return (new_node);
	split = ft_split(argv, ' ');
	num_strings = 0;
	while (split[num_strings] != NULL)
		num_strings++;
	*total_strings += num_strings;
	i = 0;
	while (i < num_strings)
	{
		num_not_integer = ft_custom_atoll(split[i]);
		if (num_not_integer < INT_MIN || num_not_integer > INT_MAX)
			*out_of_limits -= 1;
		new_node = create_stack(ft_atoi(split[i]), new_node);
		free(split[i]);
		i++;
	}
	free(split);
	return (new_node);
}

int	parse_argvs(int argc, char **argv, t_stack_node *stack_node_a,
		t_stack_node *stack_node_b)
{
	int	i;
	int	not_allowed_char;
	int	t_str;
	int	out_lim;

	i = 1;
	while (i < argc)
	{
		signs_checker(argv[i]);
		not_allowed_char = allowed_chars(argv[i++], "0123456789 +-");
		if (not_allowed_char != 0)
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	i = 1;
	t_str = 0;
	out_lim = 0;
	while (i < argc)
		stack_node_a = split_argvs(argv[i++], &t_str, stack_node_a, &out_lim);
	integer_number(out_lim, stack_node_a);
	no_repeat_numbers(stack_node_a);
	sort_numbers(stack_node_a, stack_node_b);
	return (0);
}

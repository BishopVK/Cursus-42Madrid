/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:04:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/28 13:23:38 by danjimen         ###   ########.fr       */
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
			ft_printf("ERROR: Signo suelto o string vacío\n");
			exit(-1);
		}
	}
	//ft_printf("LEN: %i\n", ft_strlen(&argv[i]));
	while (argv[i + 1] != '\0')
	{
		if ((argv[i] != ' ' && (argv[i + 1] == '+' || argv[i + 1] == '-'))
			|| ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] == ' '))
		{
			ft_printf("ERROR: Sin espacio antes o después de un signo\n");
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
	split = ft_split(argv, ' '); // Realizar split a cada argumento
	num_strings = 0;
	while (split[num_strings] != NULL) // Contar cuántos elementos no nulos hay
		num_strings++;
	*total_strings += num_strings;
	i = 0;
	while (i < num_strings) // Liberar la memoria asignada a cada split
	{
		num_not_integer = ft_custom_atoll(split[i]);
		if (num_not_integer < INT_MIN || num_not_integer > INT_MAX)
			*out_of_limits -= 1;
		new_node = create_stack(ft_atoi(split[i]), new_node);
		free(split[i]);
		i++;
	}
	free(split); // Liberar el array bidimensional
	return (new_node);
}

int	parse_argvs(int argc, char **argv, t_stack_node *stack_node_a,
		t_stack_node *stack_node_b)
{
	int	i;
	int	not_allowed_char;
	int	total_strings;
	int	out_of_limits;

	i = 1;
	while (i < argc)
	{
		signs_checker(argv[i]);
		not_allowed_char = allowed_chars(argv[i++], "0123456789 +-");
		if (not_allowed_char != 0)
		{
			ft_printf("ERROR: You have entered illegal characters\n");
			return (1);
		}
	}
	i = 1;
	total_strings = 0;
	out_of_limits = 0;
	while (i < argc)
		stack_node_a = split_argvs(argv[i++], &total_strings, stack_node_a,
				&out_of_limits);
	integer_number(out_of_limits, stack_node_a);
	no_repeat_numbers(stack_node_a);
	sort_numbers(stack_node_a, stack_node_b);
	(void)stack_node_b;
	/* display(stack_node_a);
	ft_printf("total_strings = %d\n", total_strings);
	ft_printf("%d elementos en el stack\n", stack_len(stack_node_a));
	ft_printf("Realizamos un swap\n");
	sa(&stack_node_a);
	display(stack_node_a);
	ft_printf("%d elementos en el stack\n", stack_len(stack_node_a));
	ft_printf("Vaciamos el stack\n");
	stack_clear(&stack_node_a);
	display(stack_node_b); */
	return (0);
}

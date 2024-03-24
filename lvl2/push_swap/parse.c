/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:04:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/24 23:12:27 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	integer_number(int out_of_limits, t_stack_node *stack_node_a)
{
	if (out_of_limits < 0)
	{
		stack_clear(&stack_node_a);
		ft_printf("Error: Number out of INT limits\n");
		exit(-1);
	}
}

void	no_repeat_numbers(t_stack_node *stack_node_a)
{
	t_stack_node	*local_node;
	t_stack_node	*tmp_node;

	local_node = stack_node_a;
	if (local_node == NULL)
		ft_printf("Empty Stack\n");
	else
	{
		while (local_node)
		{
			tmp_node = local_node->next;
			while (tmp_node)
			{
				if (local_node->nb == tmp_node->nb)
				{
					ft_printf("ERROR: %d is duplicate\n", local_node->nb);
					stack_clear(&stack_node_a);
					exit(-1);
				}
				tmp_node = tmp_node->next;
			}
			local_node = local_node->next;
		}
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
	int		i;
	char	**split;
	int		num_strings;
	long	num_not_integer;

	split = ft_split(argv, ' '); // Realizar split a cada argumento
	num_strings = 0;
	while (split[num_strings] != NULL) // Contar cuántos elementos no nulos hay
		num_strings++;
	*total_strings += num_strings;
	i = 0;
	while (i < num_strings) // Liberar la memoria asignada a cada split
	{
		num_not_integer = ft_atol(split[i]);
		if (num_not_integer < INT_MIN || num_not_integer > INT_MAX)
			*out_of_limits -= 1;
		new_node = push(ft_custom_atoi(split[i]), new_node);
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
	//sort_numbers(stack_node_a, stack_node_b);
	/* ft_printf("total_strings = %d\n", total_strings);
	display(stack_node_a);
	ft_printf("%d elementos en el stack\n", stack_len(stack_node_a));
	ft_printf("Realizamos un swap\n");
	sa(&stack_node_a);
	display(stack_node_a);
	ft_printf("%d elementos en el stack\n", stack_len(stack_node_a));
	ft_printf("Vaciamos el stack\n");
	stack_clear(&stack_node_a); */
	display(stack_node_b);
	return (0);
}

/* int	parse_argvs(int argc, char **argv, t_stack_node *new_node)
{
	int		i;
	int		not_allowed_char;
	char	*allowed;
	int		total_strings;

	allowed = ft_strdup("0123456789 +-");
	i = 1;
	while (i < argc)
	{
		not_allowed_char = allowed_chars(argv[i++], allowed);
		if (not_allowed_char != 0)
		{
			ft_printf("Has introducido caracteres no permitidos\n");
			return (1);
		}
	}
	i = 1;
	while (i < argc)
		new_node = split_argvs(argv[i++], &total_strings, new_node);
	ft_printf("total_strings = %d\n", total_strings);
	display(new_node);
	no_repeat_numbers(new_node);
	ft_printf("HOLA");
	return (0);
} */
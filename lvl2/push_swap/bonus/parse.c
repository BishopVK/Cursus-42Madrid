/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:56:07 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/11 13:06:07 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	no_repeat_numbers(t_stack_node *stack_node_a)
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

static void	integer_number(int out_of_limits, t_stack_node *stack_node_a)
{
	if (out_of_limits < 0)
	{
		stack_clear(&stack_node_a);
		ft_printf("Error: Number out of INT limits\n");
		exit(-1);
	}
}

static int	allowed_chars(char *argv, char *allowed)
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

static void	signs_checker(char *argv)
{
	int	i;

	i = 0;
	if (ft_strlen(&argv[i]) < 2)
	{
		if (ft_isdigit(argv[i]))
			return ;
		else
		{
			ft_dprintf(2, "Error\n");
			exit(-1);
		}
	}
	while (argv[i + 1] != '\0')
	{
		if ((argv[i] != ' ' && (argv[i + 1] == '+' || argv[i + 1] == '-'))
			|| ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] == ' '))
		{
			ft_dprintf(2, "Error\n");
			exit(-1);
		}
		i++;
	}
}

int	parse_argvs(int argc, char **argv, t_stack_node **stack_node_a)
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
			ft_dprintf(2, "Error\n");
			return (1);
		}
	}
	i = 1;
	t_str = 0;
	out_lim = 0;
	while (i < argc)
		*stack_node_a = split_argvs(argv[i++], &t_str, *stack_node_a, &out_lim);
	integer_number(out_lim, *stack_node_a);
	no_repeat_numbers(*stack_node_a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:47:53 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/04 20:06:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_one_element(t_stack_node *stack_node_a)
{
	if (stack_node_a == NULL)
	{
		exit(-1);
	}
	else if (stack_node_a->next == NULL)
	{
		stack_clear(&stack_node_a);
		exit(0);
	}
}

void	its_ordered(t_stack_node *stack_node_a)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;

	only_one_element(stack_node_a);
	current_node = stack_node_a;
	next_node = current_node->next;
	if (current_node && next_node)
	{
		while (next_node)
		{
			if (current_node->nb > next_node->nb)
				break ;
			current_node = next_node;
			next_node = current_node->next;
		}
		if (current_node->next == NULL)
		{
			stack_clear(&stack_node_a);
			exit(0);
		}
	}
}

void	sort_numbers(t_stack_node *stack_node_a, t_stack_node *stack_node_b)
{
	its_ordered(stack_node_a);
	assign_order(stack_node_a);
	assign_half(stack_node_a);
	if (stack_len(stack_node_a) <= 5)
		sort_short(&stack_node_a, &stack_node_b);
	else
		turk_sort(&stack_node_a, &stack_node_b);
	stack_clear(&stack_node_a);
	stack_clear(&stack_node_b);
	exit(0);
}

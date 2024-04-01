/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:08:10 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/01 20:00:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Con Half
void	short_algorithm(t_stack_node **stack_node_a,
			t_stack_node **stack_node_b)
{
	int				i;
	int				half;
	t_stack_node	*local_node_a;

	i = 1;
	half = 0;
	while (stack_len(*stack_node_a) > 3)
	{
		local_node_a = *stack_node_a;
		while (local_node_a->order != i)
			local_node_a = local_node_a->next;
		half = local_node_a->half;
		while ((*stack_node_a)->order != i)
		{
			if (half == UP)
				ra(stack_node_a);
			else
				rra(stack_node_a);
		}
		pb(stack_node_a, stack_node_b);
		i++;
	}
	sort_3_numbers(stack_node_a);
	while (stack_len(*stack_node_b) > 0)
		pa(stack_node_a, stack_node_b);
}

void	sort_3_numbers(t_stack_node **stack_node_a)
{
	t_stack_node	*first;

	first = *stack_node_a;
	if (first->order < first->next->next->order
		&& first->next->next->order < first->next->order)
	{
		sa(stack_node_a);
		ra(stack_node_a);
	}
	else if (first->next->order < first->order
		&& first->order < first->next->next->order)
		sa(stack_node_a);
	else if (first->next->next->order < first->order
		&& first->order < first->next->order)
		rra(stack_node_a);
	else if (first->next->order < first->next->next->order
		&& first->next->next->order < first->order)
		ra(stack_node_a);
	else if (first->next->next->order < first->next->order
		&& first->next->order < first->order)
	{
		ra(stack_node_a);
		sa(stack_node_a);
	}
}

void	sort_short(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	if (stack_len(*stack_node_a) == 2)
		sa(stack_node_a);
	else if (stack_len(*stack_node_a) == 3)
		sort_3_numbers(stack_node_a);
	else
		short_algorithm(stack_node_a, stack_node_b);
}

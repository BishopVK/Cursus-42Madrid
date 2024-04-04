/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_b_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:47:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/03 18:47:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rearrangement_stack(t_stack_node **stack_a)
{
	t_stack_node	*local_a;
	int				i;

	local_a = *stack_a;
	i = 0;
	while (local_a)
	{
		if (local_a->order != 1)
			i++;
		else
			break ;
		local_a = local_a->next;
	}
	local_a = *stack_a;
	if (i < (stack_len(*stack_a) - i))
	{
		while (i-- > 0)
			ra(stack_a);
	}
	else
	{
		while ((stack_len(*stack_a) - i++) > 0)
			rra(stack_a);
	}
}

int	find_higher(t_stack_node *local_a, int num_b)
{
	int				higher;
	t_stack_node	*current;

	higher = INT_MAX;
	current = local_a;
	while (current)
	{
		if (current->order > num_b && current->order < higher)
		{
			higher = current->order;
		}
		current = current->next;
	}
	return (higher);
}

void	movements_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
			int *min, int *max)
{
	int	higher;

	while (*stack_b)
	{
		higher = find_higher(*stack_a, (*stack_b)->order);
		find_min_max(*stack_a, min, max);
		if ((*stack_b)->order > *max || (*stack_b)->order < *min)
		{
			while ((*stack_a)->order != *min)
				rra(stack_a);
			pa(stack_a, stack_b);
		}
		else
		{
			while ((*stack_a)->order != higher)
				rra(stack_a);
			pa(stack_a, stack_b);
		}
	}
}

void	return_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				min;
	int				max;

	movements_b_to_a(stack_a, stack_b, &min, &max);
	rearrangement_stack(stack_a);
}

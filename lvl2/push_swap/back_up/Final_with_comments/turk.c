/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:45:11 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/31 00:45:11 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function is responsible for locating for each node in stack_a its pair
// in stack_b as long as it is not outside the min and max limits of stack_b
void	nb_inside_limits(t_stack_node *local_a, t_stack_node **stack_a,
			t_stack_node *local_b, t_stack_node **stack_b)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (i < INT_MAX)
	{
		*stack_b = local_b;
		while (*stack_b)
		{
			if ((*stack_b)->order == (*stack_a)->order - i)
			{
				(*stack_a)->pair_order = (*stack_b)->order;
				final_cost(local_a, stack_a, local_b, stack_b);
				flag = 1;
				break ;
			}
			*stack_b = (*stack_b)->next;
		}
		if (flag != 0)
			break ;
		i++;
	}
}

// This function locates and updates the value of the maximum
// and minimum number that is on the stack.
void	find_min_max(t_stack_node *stack, int *min, int *max)
{
	*min = stack->order;
	*max = stack->order;
	while (stack)
	{
		if (stack->order < *min)
			*min = stack->order;
		else if (stack->order > *max)
			*max = stack->order;
		stack = stack->next;
	}
}

// This function is responsible for locating the pair of number
// (that of stack_a and that of stack_b that must be placed
// at the top of the stack) to calculate the cost.
void	find_pair(t_stack_node **stack_a, t_stack_node **stack_b,
			int *min, int *max)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;

	local_a = *stack_a;
	local_b = *stack_b;
	find_min_max(*stack_b, min, max);
	while (*stack_a)
	{
		*stack_b = local_b;
		if ((*stack_a)->order < *min || (*stack_a)->order > *max)
		{
			while ((*stack_b)->order != *max)
				*stack_b = (*stack_b)->next;
			(*stack_a)->pair_order = (*stack_b)->order;
			final_cost(local_a, stack_a, local_b, stack_b);
		}
		else
			nb_inside_limits(local_a, stack_a, local_b, stack_b);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = local_a;
	*stack_b = local_b;
}

// This function is responsible for looping through each node
// in stack_a and finding which node in stack_b should be placed
// on top to calculate the final cost of moving a node.
void	less_node_cost(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				min_b;
	int				max_b;
	int				len_a;

	min_b = 0;
	max_b = 0;
	len_a = stack_len(*stack_a);
	find_pair(stack_a, stack_b, &min_b, &max_b);
	while (len_a > 3) // Mover los nodos de menor coste de stack_a a stack_b
	{
		push_a_to_b(stack_a, stack_b);
		find_pair(stack_a, stack_b, &min_b, &max_b);
		len_a--;
	}
	sort_3_numbers(stack_a); // Ordenar los 3 últimos nodos de stack_a
	return_b_to_a(stack_a, stack_b); // Mover los nodos de stack_b a stack_a
}

// This is the main function and is responsible for performing
// the first 2 movements and calling the rest of the functions
void	turk_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_a == NULL && stack_b != NULL)
		return ;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	less_node_cost(stack_a, stack_b);
}

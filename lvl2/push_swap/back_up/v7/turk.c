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

void	less_node_cost(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				min_b;
	int				max_b;
	//int			nb_less_cost;
	t_stack_node	*local_a;
	t_stack_node	*local_b;
	int				i;

	min_b = 0;
	max_b = 0;
	local_a = *stack_a;
	local_b = *stack_b;

	find_min_max(*stack_b, &min_b, &max_b);
	while(local_a)
	{
		if (local_a->order < min_b || local_a->order > max_b)
		{
			while (local_b->order != max_b)
				local_b = local_b->next;
			//final_cost(local_a, local_b);
		}
		else
		{
			local_b = *stack_b;
			i = 1;
			while (i < stack_len(*stack_b))
			{
				if (local_b != NULL)
				{
					if (local_b->order == local_a->order - i)
						break;
				}
				local_b = local_b->next;
				i++;
			}
		}
		local_a = local_a->next;
	}


	//nb_less_cost = find_less_cost(*stack_a);

	/* while ((*stack_a)->cost > nb_less_cost)
		*stack_a = (*stack_a)->next; */

	ft_printf("min = %d\n", min_b);
	ft_printf("max = %d\n", max_b);
	//ft_printf("less = %d\n", nb_less_cost);
}

/* int	find_less_cost(t_stack_node *stack)
{
	int	less;

	less = stack->cost;
	while (stack)
	{
		if (stack->cost < less)
			less = stack->cost;
		stack = stack->next;
	}
	return (stack->order);
} */

void	assign_cost(t_stack_node *a, t_stack_node **stack)
{
	int	i;

	i = 0;
	while (a)
	{
		ft_printf("stack a:<< i = %d, len = %d\n", i, stack_len(*stack));
		if (i < (stack_len(*stack) - i))
		{
			ft_printf("nb: %d\n", a->nb);
			a->cost = i;
		}
		else
		{
			a->cost = (stack_len(*stack) - i);
		}
		i++;
		a = a->next;
	}
}

void	calc_cost(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = *stack_a;
	b = *stack_b;
	assign_cost(a, stack_a);
	assign_cost(b, stack_b);
}

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

void	turk_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_a == NULL && stack_b != NULL)
		return ;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	calc_cost(stack_a, stack_b);
	less_node_cost(stack_a, stack_b);
}

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

/* int	find_higher(t_stack_node *local_a, t_stack_node *local_b)
{
	int				i;
	int				flag;
	int				higher;
	t_stack_node	*head;

	head = local_a;
	i = 1;
	flag = 0;
	while (i < INT_MAX)
	{
		local_a = head;
		while (local_a)
		{
			if (local_a->order == local_b->order + i)
			{
				higher = local_a->order;
				flag = 1;
				break ;
			}
			local_a = local_a->next;
		}
		if (flag != 0)
			break ;
		i++;
	}
	return(higher);
} */

int find_higher(t_stack_node *local_a, t_stack_node *local_b)
{
	int				higher;
	t_stack_node	*current_a;
	t_stack_node	*current_b;

	higher = 0;
	current_a = local_a;
	current_b = local_b;
	while (current_a) // Recorre el Stack A
	{
		if (current_a->order > current_b->order) // Si el número en el Stack A es mayor que el número en el Stack B
		{
			// Si es el primer número mayor encontrado o es más pequeño que el número previamente encontrado,
			// actualiza el número más pequeño mayor
			if (higher == 0 || current_a->order < higher)
			{
				higher = current_a->order;
			}
		}
		current_a = current_a->next;
	}

	return (higher);
}

void	movements_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
			int *min, int *max)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;
	int				higher;

	local_a = *stack_a;
	local_b = *stack_b;
	while (*stack_b)
	{
		local_a = *stack_a;
		higher = find_higher(local_a, local_b);
		find_min_max(*stack_a, min, max);
		if ((*stack_b)->order > *max || (*stack_b)->order < *min)
		{
			while ((*stack_a)->order != *min)
				rra(stack_a);
			pa(stack_a, stack_b);
		}
		else
		{
			if ((*stack_a)->order == higher)
				pa(stack_a, stack_b);
			else
				rra(stack_a);
		}
	}
}

void	return_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				min;
	int				max;
	//t_stack_node	*local_a;
	//int				half;

	movements_b_to_a(stack_a, stack_b, &min, &max);
	/* local_a = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->order == 1)
			half = (*stack_a)->half;
		*stack_a = (*stack_a)->next;
	}
	ft_printf("%d->half = %d\n", (*stack_a)->order, half);
	*stack_a = local_a; */
	/* while ((*stack_a)->order != 1)
	{

	} */
	/* while (*stack_b)
	{
		local_a = *stack_a;
		local_b = *stack_b;
		higher = find_higher(local_a, local_b);
		find_min_max(*stack_a, &min, &max);
		ft_printf("%d order = %d\n", local_b->nb ,local_b->order);
		ft_printf("Objetivo = %d\n", max);
		ft_printf("min = %d\n", min);
		ft_printf("max = %d\n", max);
		if ((*stack_b)->order > max || (*stack_b)->order < min)
		{
			while ((*stack_a)->order != min)
				rra(stack_a);
			pa(stack_a, stack_b);
		}
		else
		{
			if ((*stack_a)->order == higher)
				pa(stack_a, stack_b);
			else
				rra(stack_a);
		}
	} */
	
}
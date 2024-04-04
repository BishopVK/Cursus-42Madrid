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

/* int find_higher(t_stack_node *local_a, t_stack_node *local_b)
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
} */

// Mi último código
/* int find_higher(t_stack_node *local_a, t_stack_node *local_b)
{
	int				higher;
	int				i;
	int				flag;
	t_stack_node	*current_a;

	higher = 0;
	current_a = local_a;
	i = 1;
	flag = 0;
	while (i < INT_MAX) // Recorre el Stack A
	{
		current_a = local_a;
		while (current_a) // Recorre el Stack A
		{
			if (current_a->order == local_b->order + i)
			{
				higher = current_a->order;
				flag = 1;
				break ;
			}
			current_a = current_a->next;
		}
		if (flag != 0)
			break ;
		i++;
	}
	return (higher);
} */

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
	//t_stack_node	*local_a;
	//t_stack_node	*local_b;
	int				higher;

	//local_a = *stack_a;
	//local_b = *stack_b;
	while (*stack_b)
	{
		higher = find_higher(*stack_a, (*stack_b)->order);
		//local_a = *stack_a;
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
	t_stack_node	*local_a;
	int				i;

	movements_b_to_a(stack_a, stack_b, &min, &max);
	
	//Rotar el stack para dejar el 1 arriba
	local_a = *stack_a;
	//ft_printf("stack_len(*stack_a) = %d\n", stack_len(*stack_a));
	//ft_printf("stack_len(local_a) = %d\n", stack_len(local_a));
	i = 0;

	/* // Buscar el número 1 en el stack y contar cuántas veces necesitamos rotar
	while (current && current->order != 1) {
		current = current->next;
		i++;
	}

	// Rotar el stack para dejar el número 1 en la parte superior
	while (i > 0)
	{
		// Implementa rra(stack_a) aquí para rotar hacia la derecha
		// Esto debería mover el elemento superior del stack al fondo
		i--;
	} */

	while (local_a)
	{
		if (local_a->order != 1)
			i++;
		else
			break ;
		local_a = local_a->next;
	}
	//ft_printf("i = %d\n", i);
	local_a = *stack_a;

	// ft_printf("stack_len(*stack_a) = %d\n", stack_len(*stack_a));
	// ft_printf("stack_len(local_a) = %d\n", stack_len(local_a));

	if (i < (stack_len(*stack_a) - i))
	{
		while (i > 0)
		{
			ra(stack_a);
			i--;
		}
	}
	else
	{
		while ((stack_len(*stack_a) - i) > 0)
		{
			rra(stack_a);
			i++;
		}
	}

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
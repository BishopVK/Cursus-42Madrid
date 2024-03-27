/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:08:10 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/27 19:35:48 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_algorithm(t_stack_node *stack_node_a, t_stack_node *stack_node_b)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;
	int				i;

	local_a = stack_node_a;
	local_b = stack_node_b;
	i = 1;

	/* ft_printf("--Stack a--\n");
	display(local_a);
	ft_printf("--Stack b--\n");
	display(local_b); */
	while (stack_len(local_a) > 2)
	{
		while (local_a->order != i)
			ra(&local_a);
		/* ft_printf("--Stack a--\n");
		display(local_a);
		ft_printf("--Stack b--\n");
		display(local_b); */
		pb(&local_a, &local_b);
		/* ft_printf("--Stack a--\n");
		display(local_a);
		ft_printf("--Stack b--\n");
		display(local_b); */
		i++;
	}
	while (stack_len(local_b) > 0)
		pa(&local_a, &local_b);
	ft_printf("--Stack a--\n");
	display(local_a);
	ft_printf("--Stack b--\n");
	display(local_b);
}

/* void	short_algorithm(t_stack_node *stack_node_a, t_stack_node *stack_node_b)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;
	int				i;

	local_a = stack_node_a;
	local_b = stack_node_b;
	i = 1;

	/* ft_printf("--Stack a--\n");
	display(local_a);
	ft_printf("--Stack b--\n");
	display(local_b); */
	while (stack_len(local_a) > 1)
	{
		while (local_a->order != i)
			ra(&local_a);
		/* ft_printf("--Stack a--\n");
		display(local_a);
		ft_printf("--Stack b--\n");
		display(local_b); */
		pb(&local_a, &local_b);
		/* ft_printf("--Stack a--\n");
		display(local_a);
		ft_printf("--Stack b--\n");
		display(local_b); */
		i++;
	}
	while (stack_len(local_b) > 0)
		pa(&local_a, &local_b);
	ft_printf("--Stack a--\n");
	display(local_a);
	ft_printf("--Stack b--\n");
	display(local_b);
} */

void	sort_3_numbers(t_stack_node *stack_node_a)
{
	t_stack_node	*local_node;

	local_node = stack_node_a;
	if (local_node->order == 1)
	{
		ra(&stack_node_a);
		sa(&stack_node_a);
		rra(&stack_node_a);
	}
	else if (local_node->order == 2 && local_node->next->order == 1)
		sa(&stack_node_a);
	else if (local_node->order == 2 && local_node->next->order == 3)
		rra(&stack_node_a);
	else if (local_node->order == 3 && local_node->next->order == 1)
		ra(&stack_node_a);
	else if (local_node->order == 3 && local_node->next->order == 2)
	{
		ra(&stack_node_a);
		sa(&stack_node_a);
	}
}

void	sort_short(t_stack_node *stack_node_a)
{
	if (stack_len(stack_node_a) == 2)
		sa(&stack_node_a);
	else if (stack_len(stack_node_a) == 3)
		sort_3_numbers(stack_node_a);
}
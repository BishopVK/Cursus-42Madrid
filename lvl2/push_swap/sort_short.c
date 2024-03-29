/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:08:10 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/29 11:17:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	short_algorithm(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;
	int				i;

	local_a = *stack_node_a;
	local_b = *stack_node_b;
	i = 1;
	ft_printf("--Stack a--\n");
	display(*stack_node_a);
	ft_printf("--Stack b--\n");
	display(*stack_node_b);
	ft_printf("LEN = %i\n", stack_len(local_a));
	while (stack_len(local_a) > 3)
	{
		while (local_a->order != i)
		{
			ft_printf("order de %i = %i\n", local_a->nb, local_a->order);
			ra(stack_node_a);
			ft_printf("--Stack a--\n");
			display(*stack_node_a);
			ft_printf("--Stack b--\n");
			display(*stack_node_b);
			local_a = *stack_node_a;
		}
		ft_printf("LEN = %i\n", stack_len(local_a));
		ft_printf("--Stack a--\n");
		display(*stack_node_a);
		ft_printf("--Stack b--\n");
		display(*stack_node_b);
		pb(stack_node_a, stack_node_b);
		local_a = *stack_node_a;
		local_b = *stack_node_b;
		ft_printf("--Stack a--\n");
		display(*stack_node_a);
		ft_printf("--Stack b--\n");
		display(*stack_node_b);
		i++;
		ft_printf("LEN = %i\n", stack_len(local_a));
	}
	ft_printf("FUCK!\n");
	sort_3_numbers(stack_node_a);
	while (stack_len(local_b) > 0)
	{
		pa(stack_node_a, stack_node_b);
		local_a = *stack_node_a;
		local_b = *stack_node_b;
	}
	ft_printf("--Stack a--\n");
	display(*stack_node_a);
	ft_printf("--Stack b--\n");
	display(*stack_node_b);
} */

// Con Half
void	short_algorithm(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
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

// Sin mirar el HALF
/* void	short_algorithm(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	int				i;

	i = 1;
	while (stack_len(*stack_node_a) > 3)
	{
		while ((*stack_node_a)->order != i)
		{
			ra(stack_node_a);
		}
		pb(stack_node_a, stack_node_b);
		i++;
	}
	sort_3_numbers(stack_node_a);
	while (stack_len(*stack_node_b) > 0)
	{
		pa(stack_node_a, stack_node_b);
	}
} */

/* void	short_algorithm(t_stack_node *stack_node_a, t_stack_node *stack_node_b)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;
	int				i;

	local_a = stack_node_a;
	local_b = stack_node_b;
	i = 1;

	//ft_printf("--Stack a--\n");
	//display(local_a);
	//ft_printf("--Stack b--\n");
	//display(local_b);
	while (stack_len(local_a) > 1)
	{
		while (local_a->order != i)
			ra(&local_a);
		//ft_printf("--Stack a--\n");
		//display(local_a);
		//ft_printf("--Stack b--\n");
		//display(local_b);
		pb(&local_a, &local_b);
		//ft_printf("--Stack a--\n");
		//display(local_a);
		//ft_printf("--Stack b--\n");
		//display(local_b);
		i++;
	}
	while (stack_len(local_b) > 0)
		pa(&local_a, &local_b);
	ft_printf("--Stack a--\n");
	display(local_a);
	ft_printf("--Stack b--\n");
	display(local_b);
} */

/* void	sort_3_numbers(t_stack_node *stack_node_a)
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
} */

void	sort_3_numbers(t_stack_node **stack_node_a)
{
	t_stack_node	*first;

	first = *stack_node_a;
	/* ft_printf(">>Stack a in sort_3_numbers<<\n");
	display(*stack_node_a); */
	if (first->order < first->next->next->order
		&& first->next->next->order < first->next->order)
	{
		ra(stack_node_a);
		sa(stack_node_a);
		rra(stack_node_a);
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
	/* ft_printf(">>Stack a at end of sort_3_numbers<<\n");
	display(*stack_node_a); */
}

void	sort_short(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	if (stack_len(*stack_node_a) == 2)
	{
		ft_printf("<<Vamos a ordenar 2 números>>\n");
		sa(stack_node_a);
	}
	else if (stack_len(*stack_node_a) == 3)
	{
		ft_printf("<<Vamos a ordenar 3 números>>\n");
		sort_3_numbers(stack_node_a);
	}
	else
	{
		ft_printf("<<Vamos a ordenar 4 o 5 números>>\n");
		short_algorithm(stack_node_a, stack_node_b);
	}
}

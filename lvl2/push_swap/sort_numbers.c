/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:57:49 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/01 22:45:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:46:50 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/24 21:46:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_one_element(t_stack_node *stack_node_a)
{
	if (stack_node_a == NULL)
	{
		ft_printf("Empty Stack\n");
		exit(-1);
	}
	else if (stack_node_a->next == NULL)
	{
		//ft_printf("Only one element on the stack. Already ordered.\n");
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
			//ft_printf("Numbers already ordered\n");
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
	//display_half(stack_node_a);
	if (stack_len(stack_node_a) <= 5)
		sort_short(&stack_node_a, &stack_node_b);
	else
	{
		ft_printf("<<Vamos a ordenar más de 5 números>>\n");
		//short_algorithm(&stack_node_a, &stack_node_b);
		turk_sort(&stack_node_a, &stack_node_b);
	}
	
	ft_printf("--STACK A--\n");
	display_cost(stack_node_a);
	ft_printf("--STACK B--\n");
	display_cost(stack_node_b);

	/*ft_printf("++Stack a in sort_numbers after sorting++\n");
	ft_printf("----stack a----\n");
	display(stack_node_a);
	ft_printf("----stack b----\n");
	display(stack_node_b);*/
	stack_clear(&stack_node_a);
	stack_clear(&stack_node_b);
	exit(0);

	//display_order(stack_node_a);
	//ft_printf("--------\n");
	//display_by_order(stack_node_a);

	/* pb(&stack_node_a, &stack_node_b);
	ft_printf("----stack a----\n");
	display(stack_node_a);
	ft_printf("----stack b----\n");
	display(stack_node_b);

	pb(&stack_node_a, &stack_node_b);
	ft_printf("----stack a----\n");
	display(stack_node_a);
	ft_printf("----stack b----\n");
	display(stack_node_b);

	pb(&stack_node_a, &stack_node_b);
	ft_printf("----stack a----\n");
	display(stack_node_a);
	ft_printf("----stack b----\n");
	display(stack_node_b);

	rra(&stack_node_a);
	ft_printf("----stack a----\n");
	display(stack_node_a);
	ft_printf("----stack b----\n");
	display(stack_node_b);

	rrb(&stack_node_b);
	ft_printf("----stack a----\n");
	display(stack_node_a);
	ft_printf("----stack b----\n");
	display(stack_node_b);

	ft_printf("----reverse rotate both----\n");
	rrr(&stack_node_a, &stack_node_b);
	ft_printf("----stack a----\n");
	display(stack_node_a);
	ft_printf("----stack b----\n");
	display(stack_node_b); */
}

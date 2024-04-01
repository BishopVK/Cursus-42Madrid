/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:05:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/24 11:05:14 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **node)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	first_node = *node;
	second_node = (*node)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*node = second_node;
}

void	sa(t_stack_node **stack_node_a)
{
	swap(stack_node_a);
	assign_half(*stack_node_a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **stack_node_b)
{
	swap(stack_node_b);
	assign_half(*stack_node_b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	swap(stack_node_a);
	swap(stack_node_b);
	assign_half(*stack_node_a);
	assign_half(*stack_node_b);
	ft_printf("ss\n");
}

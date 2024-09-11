/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:39:58 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/26 19:39:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack_node **node)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;
	t_stack_node	*tmp_node;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	first_node = *node;
	tmp_node = *node;
	while (tmp_node->next != NULL)
	{
		tmp_node = tmp_node->next;
	}
	last_node = tmp_node;
	*node = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
}

void	ra(t_stack_node **stack_node_a)
{
	rotate(stack_node_a);
}

void	rb(t_stack_node **stack_node_b)
{
	rotate(stack_node_b);
}

void	rr(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	rotate(stack_node_a);
	rotate(stack_node_b);
}

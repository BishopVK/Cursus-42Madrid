/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:35:02 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/26 21:35:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack_node **node)
{
	t_stack_node	*first_node;
	t_stack_node	*penultimate_node;
	t_stack_node	*last_node;
	t_stack_node	*tmp_node;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	first_node = *node;
	tmp_node = *node;
	while (tmp_node->next->next != NULL)
	{
		tmp_node = tmp_node->next;
	}
	penultimate_node = tmp_node;
	last_node = tmp_node->next;
	*node = last_node;
	last_node->next = first_node;
	penultimate_node->next = NULL;
}

void	rra(t_stack_node **stack_node_a)
{
	reverse_rotate(stack_node_a);
}

void	rrb(t_stack_node **stack_node_b)
{
	reverse_rotate(stack_node_b);
}

void	rrr(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	reverse_rotate(stack_node_a);
	reverse_rotate(stack_node_b);
}

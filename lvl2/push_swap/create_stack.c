/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:30:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/28 13:27:36 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_half(t_stack_node *node)
{
	t_stack_node	*current;
	int				stack_lenght;
	int				half_stack;

	current = node;
	stack_lenght = stack_len(current);
	half_stack = stack_lenght / 2;
	while (current != NULL)
	{
		while (half_stack > 0)
		{
			current->half = UP;
			current = current->next;
			half_stack--;
		}
		current->half = DOWN;
		current = current->next;
	}
}

void	assign_order(t_stack_node *node)
{
	t_stack_node	*current;
	t_stack_node	*temp;
	int				smaller_count;

	current = node;
	while (current != NULL)
	{
		smaller_count = 0;
		temp = node;
		while (temp != current)
		{
			if (temp->nb < current->nb)
				smaller_count++;
			temp = temp->next;
		}
		temp = current->next;
		while (temp != NULL)
		{
			if (temp->nb < current->nb)
				smaller_count++;
			temp = temp->next;
		}
		current->order = smaller_count + 1;
		current = current->next;
	}
}

void	stack_clear(t_stack_node **node)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = *node;
	if (*node != NULL)
	{
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*node = NULL;
	}
}

t_stack_node	*create_stack(int nbr, t_stack_node *node)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->nb = nbr;
	new_node->order = -1;
	new_node->next = NULL;
	if (node == NULL)
		return (new_node);
	current = node;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	return (node);
}

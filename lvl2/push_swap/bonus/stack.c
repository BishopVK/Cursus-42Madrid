/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:02:19 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/11 15:17:52 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	display(t_stack_node *new_node)
{
	t_stack_node	*local_node;

	local_node = new_node;
	if (local_node == NULL)
		ft_printf("Stack vacío\n");
	else
	{
		while (local_node)
		{
			ft_printf("valor = %d\n", local_node->nb);
			local_node = local_node->next;
		}
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

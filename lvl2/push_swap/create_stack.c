/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:30:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/24 18:35:29 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack_node	*push(int nbr, t_stack_node *node)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->nb = nbr;
	new_node->next = NULL;
	if (node == NULL)
		return (new_node);
	current = node;
	while (current->next != NULL)
		current = current->next;

	current->next = new_node;
		
	return (node);
}

// Introducir en orden inverso
/* t_stack_node	*push(int nbr, t_stack_node *new_node)
{
	t_stack_node	*local_node;

	local_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!local_node)
		return (NULL);
	if (new_node == NULL)
	{
		local_node->nb = nbr;
		local_node->next = NULL;
	}
	else
	{
		local_node->nb = nbr;
		local_node->next = new_node;
	}
	return (local_node);
} */
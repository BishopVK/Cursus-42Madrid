/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:30:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/28 12:55:27 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


void	integer_number(int out_of_limits, t_stack_node *stack_node_a)
{
	if (out_of_limits < 0)
	{
		stack_clear(&stack_node_a);
		ft_printf("Error: Number out of INT limits\n");
		exit(-1);
	}
}

void	no_repeat_numbers(t_stack_node *stack_node_a)
{
	t_stack_node	*local_node;
	t_stack_node	*tmp_node;

	local_node = stack_node_a;
	if (local_node == NULL)
		ft_printf("Empty Stack\n");
	else
	{
		while (local_node)
		{
			tmp_node = local_node->next;
			while (tmp_node)
			{
				if (local_node->nb == tmp_node->nb)
				{
					ft_printf("ERROR: %d is duplicate\n", local_node->nb);
					stack_clear(&stack_node_a);
					exit(-1);
				}
				tmp_node = tmp_node->next;
			}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:30:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/22 14:33:16 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_del_node_content(void *content)
{
	if (content != NULL)
		free(content);
} */

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

void	no_repeat_numbers(t_stack_node *new_node)
{
	t_stack_node	*local_node;
	t_stack_node	*tmp_node;

	local_node = new_node;
	if (local_node == NULL)
		ft_printf("Stack vacío\n");
	else
	{
		while (local_node)
		{
			tmp_node = local_node->next;
			while (tmp_node)
			{
				if (local_node->nb == tmp_node->nb)
				{
					ft_printf("valor duplicado -> %d.\n", local_node->nb);
					exit(-1);
				}
				tmp_node = tmp_node->next;
			}
			local_node = local_node->next;
		}
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

t_stack_node	*push(int nbr, t_stack_node *new_node)
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
}

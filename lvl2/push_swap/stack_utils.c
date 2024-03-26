/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:31:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/26 12:37:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *new_node)
{
	int	len;

	len = 0;
	if (new_node != NULL)
	{
		while (new_node)
		{
			new_node = new_node->next;
			len++;
		}
	}
	return (len);
}

void	display_by_order(t_stack_node *new_node)
{
	t_stack_node	*local_node;
	int				i;

	local_node = new_node;
	if (local_node == NULL)
		ft_printf("Stack vacío\n");
	else
	{
		i = 1;
		while (i <= stack_len(new_node))
		{
			while (local_node)
			{
				if (i == local_node->order)
				{
					ft_printf("%d valor = %d\n", local_node->order, local_node->nb);
					break ;
				}
				local_node = local_node->next;
			}
			local_node = new_node;
			i++;
		}
	}
}

void	display_order(t_stack_node *new_node)
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
			ft_printf("order = %d\n", local_node->order);
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

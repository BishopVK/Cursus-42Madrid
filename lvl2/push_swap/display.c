/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:17:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/28 13:17:13 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_pair(t_stack_node *new_node)
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
			ft_printf("pair = %d\n\n", local_node->pair_order);
			local_node = local_node->next;
		}
	}
}

void	display_cost(t_stack_node *new_node)
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
			ft_printf("cost = %d\n\n", local_node->cost);
			local_node = local_node->next;
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

void	display_half(t_stack_node *new_node)
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
			ft_printf("Half = %d\n", local_node->half);
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

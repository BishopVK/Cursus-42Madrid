/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:31:14 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/28 13:18:59 by danjimen         ###   ########.fr       */
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

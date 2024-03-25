/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:57:49 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/25 12:48:21 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:46:50 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/24 21:46:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_one_element(t_stack_node *stack_node_a)
{
	if (stack_node_a == NULL)
		ft_printf("Empty Stack\n");
	else if (stack_node_a->next == NULL)
	{
		ft_printf("Only one element on the stack. Already ordered.\n");
		stack_clear(&stack_node_a);
		exit(1);
	}
}

void	its_ordered(t_stack_node *stack_node_a)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;

	only_one_element(stack_node_a);
	current_node = stack_node_a;
	next_node = current_node->next;
	if (current_node && next_node)
	{
		while (next_node)
		{
			if (current_node->nb > next_node->nb)
				break ;
			current_node = next_node;
			next_node = current_node->next;
		}
		if (current_node->next == NULL)
		{
			ft_printf("Numbers already ordered\n");
			stack_clear(&stack_node_a);
			exit(1);
		}
	}
}

void	sort_numbers(t_stack_node *stack_node_a, t_stack_node *stack_node_b)
{
	its_ordered(stack_node_a);
	if (stack_node_b)
		ft_printf("HOLA!");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:09:48 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/11 13:31:19 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_lstclear_push_swap(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

static void	error(t_stack_node **a, t_stack_node **b)
{
	ft_lstclear_push_swap(a);
	ft_lstclear_push_swap(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (ft_strcmp(command, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(command, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(a, b);
	else
		error(a, b);
}
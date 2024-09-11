/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:45 by danjimen          #+#    #+#             */
/*   Updated: 2024/09/11 12:56:51 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*node_to_push;

	if (src == NULL || dst == NULL || *src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*dst == NULL)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		*dst = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
}

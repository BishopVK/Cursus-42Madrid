/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:13:03 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/03 17:13:03 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_r_its_less(t_stack_node **stack_a, t_stack_node *local_a,
			t_stack_node **stack_b, t_stack_node *local_b)
{
	if (local_a->rot <= local_b->rot)
	{
		while ((local_b->rot-- - local_a->rot) > 0)
			rb(stack_b);
		while (local_a->rot-- > 0)
			rr(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((local_a->rot-- - local_b->rot) > 0)
			ra(stack_a);
		while (local_b->rot-- > 0)
			rr(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
}

void	rr_rr_its_less(t_stack_node **stack_a, t_stack_node *local_a,
			t_stack_node **stack_b, t_stack_node *local_b)
{
	if (local_a->rev_rot <= local_b->rev_rot)
	{
		while ((local_b->rev_rot-- - local_a->rev_rot) > 0)
			rrb(stack_b);
		while (local_a->rev_rot-- > 0)
			rrr(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((local_a->rev_rot-- - local_b->rev_rot) > 0)
			rra(stack_a);
		while (local_b->rev_rot-- > 0)
			rrr(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
}

void	r_rr_its_less(t_stack_node **stack_a, t_stack_node *local_a,
			t_stack_node **stack_b, t_stack_node *local_b)
{
	while (local_a->rot-- > 0)
		ra(stack_a);
	while (local_b->rev_rot-- > 0)
		rrb(stack_b);
	pb(stack_a, stack_b);
}

void	rr_r_its_less(t_stack_node **stack_a, t_stack_node *local_a,
			t_stack_node **stack_b, t_stack_node *local_b)
{
	while (local_a->rev_rot-- > 0)
		rra(stack_a);
	while (local_b->rot-- > 0)
		rb(stack_b);
	pb(stack_a, stack_b);
}

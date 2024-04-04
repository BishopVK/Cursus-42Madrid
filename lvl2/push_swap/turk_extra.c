/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:31:04 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/01 21:31:04 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function calculates the cost of moving each node by doing rotate
// and reverse rotate and saves the value inside the node
void	assign_rot_rev_rot(t_stack_node *local, t_stack_node **stack)
{
	t_stack_node	*tmp;
	int				len;
	int				i;

	len = stack_len(local);
	tmp = local;
	while (local)
	{
		i = 0;
		while (local && local->order != (*stack)->order)
		{
			i++;
			local = local->next;
		}
		(*stack)->rot = i;
		(*stack)->rev_rot = len - i;
		break ;
		if (local)
			local = local->next;
	}
	local = tmp;
}

// This function calculates the final cost of moving a node from stack a
// to stack b, counting the movements of both stacks
void	final_cost(t_stack_node *a, t_stack_node **stack_a,
			t_stack_node *b, t_stack_node **stack_b)
{
	int	r_r;
	int	rr_rr;
	int	r_rr;
	int	rr_r;

	assign_rot_rev_rot(a, stack_a);
	assign_rot_rev_rot(b, stack_b);
	if ((*stack_a)->rot >= (*stack_b)->rot)
		r_r = (*stack_a)->rot + 1;
	else
		r_r = (*stack_b)->rot + 1;
	if ((*stack_a)->rev_rot >= (*stack_b)->rev_rot)
		rr_rr = (*stack_a)->rev_rot + 1;
	else
		rr_rr = (*stack_b)->rev_rot + 1;
	r_rr = (*stack_a)->rot + (*stack_b)->rev_rot + 1;
	rr_r = (*stack_a)->rev_rot + (*stack_b)->rot + 1;
	(*stack_a)->cost = r_r;
	if (rr_rr < (*stack_a)->cost)
		(*stack_a)->cost = rr_rr;
	if (r_rr < (*stack_a)->cost)
		(*stack_a)->cost = r_rr;
	if (rr_r < (*stack_a)->cost)
		(*stack_a)->cost = rr_r;
}

// This function goes through the stack to return
// the node that has the lowest cost
t_stack_node	*find_less_cost(t_stack_node *stack)
{
	t_stack_node	*less;

	less = stack;
	while (stack)
	{
		if (stack->cost < less->cost)
			less = stack;
		stack = stack->next;
	}
	return (less);
}

void	push_node(t_stack_node **stack_a, t_stack_node *local_a,
			t_stack_node **stack_b, t_stack_node *local_b)
{
	int	r_r;
	int	rr_rr;
	int	r_rr;
	int	rr_r;

	if (local_a->rot >= local_b->rot)
		r_r = local_a->rot + 1;
	else
		r_r = local_b->rot + 1;
	if (local_a->rev_rot >= local_b->rev_rot)
		rr_rr = local_a->rev_rot + 1;
	else
		rr_rr = local_b->rev_rot + 1;
	r_rr = local_a->rot + local_b->rev_rot + 1;
	rr_r = local_a->rev_rot + local_b->rot + 1;
	if (r_r <= rr_rr && r_r <= r_rr && r_r <= rr_r) // Rotar ambos stacks
		r_r_its_less(stack_a, local_a, stack_b, local_b);
	else if (rr_rr <= r_r && rr_rr <= r_rr && rr_rr <= rr_r) // Rotar inversamente ambos stacks
		rr_rr_its_less(stack_a, local_a, stack_b, local_b);
	else if (r_rr <= r_r && r_rr <= rr_rr && r_rr <= rr_r) // Rotar A y rotar inversamente B
		r_rr_its_less(stack_a, local_a, stack_b, local_b);
	else // Rotar inversamente A y rotar B
		rr_r_its_less(stack_a, local_a, stack_b, local_b);
}

// This function must locate the node with the lowest value and perform
// the necessary operations to push it to the stack b.
void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;
	int				less_a;

	local_a = *stack_a;
	local_b = *stack_b;
	less_a = (*stack_a)->cost;
	while (*stack_a) // Encontrar el coste mínimo
	{
		if ((*stack_a)->cost < less_a)
			less_a = (*stack_a)->cost;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = local_a;
	while (local_a) // Encontrar la primera coincidencia con el coste mínimo
	{
		if (local_a->cost == less_a)
			break ;
		local_a = local_a->next;
	}
	while (local_b->order != local_a->pair_order) // Buscamos el nodo del stack_b por el que debemos intercambiarlo
		local_b = local_b->next;
	push_node(stack_a, local_a, stack_b, local_b);
}

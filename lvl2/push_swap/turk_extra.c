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
		/* ft_printf("Llamada: %d\n", i);
		ft_printf("%d->rot = %d\n", (*stack)->nb, (*stack)->rot);
		ft_printf("%d->rev_rot = %d\n", (*stack)->nb, (*stack)->rev_rot); */
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
	/* ft_printf("--Nodo a--\n");
	ft_printf("%d->rot = %d\n", (*stack_a)->nb, (*stack_a)->rot);
	ft_printf("%d->rev_rot = %d\n", (*stack_a)->nb, (*stack_a)->rev_rot);
	ft_printf("--Nodo b--\n");
	ft_printf("%d->rot = %d\n", (*stack_b)->nb, (*stack_b)->rot);
	ft_printf("%d->rev_rot = %d\n", (*stack_b)->nb, (*stack_b)->rev_rot); */
	if ((*stack_a)->rot >= (*stack_b)->rot)
		r_r = (*stack_a)->rot + 1;
	else if ((*stack_a)->rot <= (*stack_b)->rot)
		r_r = (*stack_b)->rot + 1;
	if ((*stack_a)->rev_rot >= (*stack_b)->rev_rot)
		rr_rr = (*stack_a)->rev_rot + 1;
	else if ((*stack_a)->rev_rot <= (*stack_b)->rev_rot)
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

/* void	push_node()
{

} */

void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*local_a;
	
	local_a = *stack_a;
	ft_printf("Len =  %d\n", stack_len(local_a));
	while (stack_len(local_a) > 3)
	{
		*stack_a = find_less_cost(*stack_a); // Aquí tengo el nodo con menor coste
		if (local_a == *stack_a)
			local_a = local_a->next;
		ft_printf("El node que menor coste tiene es %d\n", (*stack_a)->nb);
		//push_node(stack_a, stack_b);
		pb(stack_a, stack_b);
		ft_printf("El primer nodo de stack_a es %d\n", (*stack_a)->nb);
		ft_printf("El primer nodo de stack_b es %d\n", (*stack_b)->nb);
		ft_printf("Len =  %d\n", stack_len(local_a));
	}
}

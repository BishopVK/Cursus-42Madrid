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

void	push_node(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	r_r;
	int	rr_rr;
	int	r_rr;
	int	rr_r;

	if ((*stack_a)->rot >= (*stack_b)->rot)
	{
		r_r = (*stack_a)->rot + 1;
		ft_printf("r_r1 = %d\n", r_r);
	}
	else
	{
		r_r = (*stack_b)->rot + 1;
		ft_printf("r_r2 = %d\n", r_r);
	}
	if ((*stack_a)->rev_rot >= (*stack_b)->rev_rot)
	{
		rr_rr = (*stack_a)->rev_rot + 1;
		ft_printf("rr_rr1 = %d\n", rr_rr);
	}
	else
	{
		rr_rr = (*stack_b)->rev_rot + 1;
		ft_printf("rr_rr2 = %d\n", rr_rr);
	}
	r_rr = (*stack_a)->rot + (*stack_b)->rev_rot + 1;
	ft_printf("r_rr = %d\n", r_rr);
	rr_r = (*stack_a)->rev_rot + (*stack_b)->rot + 1;
	
	/* (*stack_a)->cost = r_r;
	if (rr_rr < (*stack_a)->cost)
		(*stack_a)->cost = rr_rr;
	if (r_rr < (*stack_a)->cost)
		(*stack_a)->cost = r_rr;
	if (rr_r < (*stack_a)->cost)
		(*stack_a)->cost = rr_r; */

	//t_stack_node *local_a = *stack_a;
	//t_stack_node *local_b = *stack_b;

	if (r_r <= rr_rr && r_r <= r_rr && r_r <= rr_r) // Rotar ambos stacks
	{
		ft_printf("r_r es el menor\n");
		// Si rotar A es más barato, realiza la rotación en A
		if ((*stack_a)->cost == (*stack_a)->rot + 1)
		{
			ft_printf("A es más barato\n");
			while ((*stack_a)->rot > 0)
			{
				rr(stack_a, stack_b);
				(*stack_a)->rot--;
			}
			while (((*stack_b)->rot - (*stack_a)->rot) > 0)
			{
				rb(stack_b);
				(*stack_b)->rot--;
			}
			pb(stack_a, stack_b);
		}
		else
		{
			ft_printf("B es más barato\n");
			while ((*stack_b)->rot > 0)
			{
				rr(stack_a, stack_b);
				(*stack_b)->rot--;
			}
			while (((*stack_a)->rot - (*stack_b)->rot) > 0)
			{
				ra(stack_a);
				(*stack_a)->rot--;
			}
			pb(stack_a, stack_b);
		}
	}
	else if (rr_rr <= r_r && rr_rr <= r_rr && rr_rr <= rr_r) // Rotar inversamente ambos stacks
	{
		ft_printf("rr_rr es el menor\n");
		// Si rotar A es más barato, realiza la rotación en A
		if ((*stack_a)->cost == (*stack_a)->rev_rot + 1)
		{
			ft_printf("A es más barato\n");
			while ((*stack_a)->rev_rot > 0)
			{
				rrr(stack_a, stack_b);
				(*stack_a)->rev_rot--;
			}
			while (((*stack_b)->rev_rot - (*stack_a)->rev_rot) > 0)
			{
				rrb(stack_b);
				(*stack_b)->rev_rot--;
			}
			pb(stack_a, stack_b);
		}
		else
		{
			ft_printf("A es más barato\n");
			while ((*stack_b)->rev_rot > 0)
			{
				rrr(stack_a, stack_b);
				(*stack_b)->rev_rot--;
			}
			while (((*stack_a)->rev_rot - (*stack_b)->rev_rot) > 0)
			{
				rra(stack_a);
				(*stack_a)->rev_rot--;
			}
			pb(stack_a, stack_b);
		}
	}
	else if (r_rr <= r_r && r_rr <= rr_rr && r_rr <= rr_r) // Rotar A y rotar inversamente B
	{
		ft_printf("r_rr es el menor\n");
		while ((*stack_a)->rot > 0)
		{
			ra(stack_a);
			(*stack_a)->rot--;
		}
		while ((*stack_b)->rev_rot > 0)
		{
			rrb(stack_b);
			(*stack_b)->rev_rot--;
		}
		pb(stack_a, stack_b);
	}
	// Si rotar inversamente B es más barato, realiza la rotación inversa en B
	else // Rotar inversamente A y rotar B
	{
		ft_printf("rr_r es el menor\n");
		while ((*stack_a)->rev_rot > 0)
		{
			rra(stack_a);
			(*stack_a)->rev_rot--;
		}
		while ((*stack_b)->rot > 0)
		{
			rb(stack_b);
			(*stack_b)->rot--;
		}
		pb(stack_a, stack_b);
	}
	ft_printf("<<STACK_A>>\n");
	display(*stack_a);
	ft_printf("<<STACK_B>>\n");
	display(*stack_b);
	// *stack_a = local_a;
	// *stack_b = local_b;
}

/* void	find_each_pair(t_stack_node **stack_a, t_stack_node **stack_b,
			int *min, int *max)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;

	local_a = *stack_a;
	local_b = *stack_b;
	find_min_max(*stack_b, min, max);
	//ft_printf("local_b->nb = %d\n", local_b->nb);

	//ft_printf("(*stack_b)->nb = %d\n", (*stack_b)->nb);
	if ((*stack_a)->order < *min || (*stack_a)->order > *max)
	{
		while ((*stack_b)->order != *max)
			*stack_b = (*stack_b)->next;
		final_cost(local_a, stack_a, local_b, stack_b);
	}
	else
		nb_inside_limits(local_a, stack_a, local_b, stack_b);
} */

// This function must locate the node with the lowest value and perform
// the necessary operations to push it to the stack b.
void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b,
			int *min, int *max)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;
	int				less;

	local_a = *stack_a;
	local_b = *stack_b;
	less = (*stack_a)->cost;
	while(*stack_a) // Encontrar el coste mínimo
	{
		if ((*stack_a)->cost < less)
			less = (*stack_a)->cost;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = local_a;

	while(*stack_a) // Encontrar la primera coincidencia con el coste mínimo
	{
		if ((*stack_a)->cost == less)
			break ;
		*stack_a = (*stack_a)->next;
	}

	// Buscamos el nodo del stack_b por el que debemos intercambiarlo
	if ((*stack_a)->order < *min || (*stack_a)->order > *max)
	{
		while ((*stack_b)->order != *max)
			*stack_b = (*stack_b)->next;
		push_node(&local_a, &local_b); // Si lo hemos encontado...
		//pb(&local_a, &local_b);
	}
	else
	{
		int	i;
		int	flag;
		i = 1;
		flag = 0;
		while (i < INT_MAX)
		{
			*stack_b = local_b;
			while (*stack_b)
			{
				if ((*stack_b)->order == (*stack_a)->order - i)
				{
					push_node(&local_a, &local_b); // Si lo hemos encontado...
					//pb(&local_a, &local_b);
					flag = 1;
					break ;
				}
				*stack_b = (*stack_b)->next;
			}
			if (flag != 0)
				break ;
			i++;
		}
	}
	*stack_a = local_a;
	*stack_b = local_b;

	ft_printf("@@@Stack_a es %d\n", (*stack_a)->nb);
	ft_printf("@@@Stack_b es %d\n", (*stack_b)->nb);
	ft_printf(">>>min es %d\n", *min);
	ft_printf(">>>max es %d\n", *max);
	ft_printf(">>>%d cost == %d\n", (*stack_a)->nb, less);
	
}

// This function must locate the node with the lowest value and perform
// the necessary operations to push it to the stack b.
/* void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b,
			int *min, int *max)
{
	t_stack_node	*local_b;
	t_stack_node	*local_a;

	local_b = *stack_b;
	ft_printf("@@@Stack_a es %d\n", (*stack_a)->nb);
	ft_printf("@@@Stack_b es %d\n", (*stack_b)->nb);
	find_each_pair(stack_a, stack_b, min, max);
	ft_printf(">>>Stack_a es %d\n", (*stack_a)->nb);
	ft_printf(">>>Stack_b es %d\n", (*stack_b)->nb);
	local_a = *stack_a;
	if (local_a == *stack_a) // Si vamos a mover el primer nodo... avanzamos local_a al segundo
		local_a = local_a->next;
	//ra(stack_a);
	//pb(stack_a, stack_b);
	//push_node(stack_a, stack_b);
	// ft_printf(">>>Stack_a es %d\n", (*stack_a)->nb);
	// ft_printf(">>>Stack_b es %d\n", (*stack_b)->nb);
	*stack_b = local_b;
	*stack_a = local_a;
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:45:11 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/31 00:45:11 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function calculates the cost of moving each node by doing rotate
// and reverse rotate and saves the value inside the node
void	assign_rot_rev_rot(t_stack_node *local, t_stack_node **stack)
{
	t_stack_node *tmp;
	int			len;
	int	i;

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
	ft_printf("--Nodo a--\n");
	ft_printf("%d->rot = %d\n", (*stack_a)->nb, (*stack_a)->rot);
	ft_printf("%d->rev_rot = %d\n", (*stack_a)->nb, (*stack_a)->rev_rot);
	ft_printf("--Nodo b--\n");
	ft_printf("%d->rot = %d\n", (*stack_b)->nb, (*stack_b)->rot);
	ft_printf("%d->rev_rot = %d\n", (*stack_b)->nb, (*stack_b)->rev_rot);
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


// This function is responsible for locating for each node in stack_a its pair
// in stack_b as long as it is not outside the min and max limits of stack_b
void	nb_inside_limits(t_stack_node *local_a, t_stack_node **stack_a,
			t_stack_node *local_b, t_stack_node **stack_b)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	while (i <= stack_len(local_b))
	{
		*stack_b = local_b;
		while (*stack_b)
		{
			if ((*stack_b)->order == (*stack_a)->order - i)
			{
				final_cost(local_a, stack_a, local_b, stack_b);
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

// This function locates and updates the value of the maximum
// and minimum number that is on the stack.
void	find_min_max(t_stack_node *stack, int *min, int *max)
{
	*min = stack->order;
	*max = stack->order;
	while (stack)
	{
		if (stack->order < *min)
			*min = stack->order;
		else if (stack->order > *max)
			*max = stack->order;
		stack = stack->next;
	}
}

// This function is responsible for locating the pair of number
// (that of stack_a and that of stack_b that must be placed
// at the top of the stack) to calculate the cost.
void	find_pair(t_stack_node **stack_a, t_stack_node **stack_b,
			int *min, int *max)
{
	t_stack_node	*local_a;
	t_stack_node	*local_b;

	local_a = *stack_a;
	local_b = *stack_b;
	find_min_max(*stack_b, min, max);
	//ft_printf("local_b->nb = %d\n", local_b->nb);
	while (*stack_a)
	{
		*stack_b = local_b;
		//ft_printf("(*stack_b)->nb = %d\n", (*stack_b)->nb);
		if ((*stack_a)->order < *min || (*stack_a)->order > *max)
		{
			while ((*stack_b)->order != *max)
				*stack_b = (*stack_b)->next;
			final_cost(local_a, stack_a, local_b, stack_b);
		}
		else
		{
			nb_inside_limits(local_a, stack_a, local_b, stack_b);
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = local_a;
	*stack_b = local_b;
}

// This function is responsible for looping through each node
// in stack_a and finding which node in stack_b should be placed
// on top to calculate the final cost of moving a node.
void	less_node_cost(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				min_b;
	int				max_b;

	min_b = 0;
	max_b = 0;
	find_pair(stack_a, stack_b, &min_b, &max_b);
}

// This function goes through the stack to return
// the value of the node that has the lowest cost
/* int	find_less_cost(t_stack_node *stack)
{
	int	less;

	less = stack->cost;
	while (stack)
	{
		if (stack->cost < less)
			less = stack->cost;
		stack = stack->next;
	}
	return (stack->order);
} */

// This function is responsible for calculating how many rotate or
// reverse rotate movements are needed to move the node to the top,
// and updates the cost with the one that returns the lowest result.
/* void	assign_cost(t_stack_node *a, t_stack_node **stack)
{
	int	i;

	i = 0;
	while (a)
	{
		ft_printf("stack a:<< i = %d, len = %d\n", i, stack_len(*stack));
		if (i < (stack_len(*stack) - i))
		{
			ft_printf("nb: %d\n", a->nb);
			a->cost = i;
		}
		else
		{
			a->cost = (stack_len(*stack) - i);
		}
		i++;
		a = a->next;
	}
} */

// This function makes the call to assign_cost() function
// to calculate the cost for both stack_a and stack_b
/* void	calc_cost(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = *stack_a;
	b = *stack_b;
	assign_cost(a, stack_a);
	assign_cost(b, stack_b);
} */

// This is the main function and is responsible for performing
// the first 2 movements and calling the rest of the functions
void	turk_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_a == NULL && stack_b != NULL)
		return ;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	//calc_cost(stack_a, stack_b);
	less_node_cost(stack_a, stack_b);
}

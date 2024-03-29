/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:39:58 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/26 19:39:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **node)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;
	t_stack_node	*tmp_node;

	if (*node == NULL || (*node)->next == NULL)
		return ; // No hay suficientes nodos para intercambiar
	first_node = *node;
	tmp_node = *node;
	while (tmp_node->next != NULL) //Llegar al último nodo
	{
		tmp_node = tmp_node->next;
	}
	last_node = tmp_node;
	// Actualizar el puntero de la cabeza si los nodos intercambiados son los primeros
	*node = first_node->next;
	// Cambiar los punteros para intercambiar los nodos
	last_node->next = first_node;
	first_node->next = NULL;
}

void	ra(t_stack_node **stack_node_a)
{
	rotate(stack_node_a);
	assign_half(*stack_node_a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack_node_b)
{
	rotate(stack_node_b);
	assign_half(*stack_node_b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	rotate(stack_node_a);
	rotate(stack_node_b);
	assign_half(*stack_node_a);
	assign_half(*stack_node_b);
	ft_printf("rr\n");
}

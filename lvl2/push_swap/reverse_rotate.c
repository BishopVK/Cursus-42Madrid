/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:35:02 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/26 21:35:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **node)
{
	t_stack_node	*first_node;
	t_stack_node	*penultimate_node;
	t_stack_node	*last_node;
	t_stack_node	*tmp_node;

	if (*node == NULL || (*node)->next == NULL)
		return ; // No hay suficientes nodos para intercambiar
	first_node = *node;
	tmp_node = *node;
	while (tmp_node->next->next != NULL) //Llegar al penúltimo nodo
	{
		tmp_node = tmp_node->next;
	}
	penultimate_node = tmp_node;
	last_node = tmp_node->next;
	// Actualizar el puntero de la cabeza si los nodos intercambiados son los primeros
	*node = last_node;
	// Cambiar los punteros para intercambiar los nodos
	last_node->next = first_node;
	penultimate_node->next = NULL;
}

void	rra(t_stack_node **stack_node_a)
{
	reverse_rotate(stack_node_a);
	assign_half(*stack_node_a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_node_b)
{
	reverse_rotate(stack_node_b);
	assign_half(*stack_node_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_node_a, t_stack_node **stack_node_b)
{
	reverse_rotate(stack_node_a);
	reverse_rotate(stack_node_b);
	assign_half(*stack_node_a);
	assign_half(*stack_node_b);
	ft_printf("rrr\n");
}
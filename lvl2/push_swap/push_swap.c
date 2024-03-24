/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:06:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/11 19:06:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cc push_swap.c push_swap.a libft/libft.a printf/libftprintf.a
//                  n min max
// ./a.out `jot -r 500 -100 100`
int	main(int argc, char *argv[])
{
	int				not_allowed_char;
	t_stack_node	*stack_node_a;
	t_stack_node	*stack_node_b;

	stack_node_a = NULL;
	stack_node_b = NULL;
	if (argc < 2)
	{
		ft_printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
		return (1);
	}
	if (argc >= 2)
	{
		not_allowed_char = parse_argvs(argc, argv, stack_node_a, stack_node_b);
		if (not_allowed_char != 0)
			return (1);
	}
	//system("leaks -q push_swap");
	return (0);
}

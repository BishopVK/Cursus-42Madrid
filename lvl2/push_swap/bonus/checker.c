/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:17:37 by sshiling          #+#    #+#             */
/*   Updated: 2024/09/11 13:30:58 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	ft_listsize(t_stack_node *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			*line;
	int				len;

	stack_a = NULL;
	stack_b = NULL;
	if (1 == argc)
		return (0);
	if (parse_argvs(argc, argv, &stack_a) != 0)
		return (1);
	len = ft_listsize(stack_a);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		command(&stack_a, &stack_b, line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(stack_a) && ft_listsize(stack_a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a);
}

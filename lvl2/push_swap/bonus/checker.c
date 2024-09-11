/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:17:37 by sshiling          #+#    #+#             */
/*   Updated: 2024/09/11 13:10:17 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_lstclear_push_swap(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

static void	error(t_stack_node **a, t_stack_node **b)
{
	ft_lstclear_push_swap(a);
	ft_lstclear_push_swap(b);
	write(2, "Error\n", 6);
	exit(1);
}

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

// cc *.c ../get_next_line/get_next_line.c ../printf/ft_dprintf.c ../printf/ft_printf.c ../printf/ft_converions.c ../printf/ft_printf_utils.c ../libft/ft_strlen.c ../libft/ft_strdup.c ../libft/ft_strchr.c ../libft/ft_isdigit.c ../libft/ft_split.c ../libft/ft_atoi.c ../libft/ft_strjoin.c ../libft/ft_strlcpy.c
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

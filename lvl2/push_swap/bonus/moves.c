/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:09:48 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/11 13:10:07 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (ft_strcmp(command, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(command, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(a, b);
	else
		error(a, b);
}
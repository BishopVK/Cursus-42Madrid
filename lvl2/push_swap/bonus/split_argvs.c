/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argvs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:05:33 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/11 12:06:22 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack_node	*split_argvs(char *argv, int *total_strings,
					t_stack_node *new_node, int *out_of_limits)
{
	int				i;
	char			**split;
	int				num_strings;
	long long int	num_not_integer;

	if (argv[0] == '\0')
		return (new_node);
	split = ft_split(argv, ' ');
	num_strings = 0;
	while (split[num_strings] != NULL)
		num_strings++;
	*total_strings += num_strings;
	i = 0;
	while (i < num_strings)
	{
		num_not_integer = ft_custom_atoll(split[i]);
		if (num_not_integer < INT_MIN || num_not_integer > INT_MAX)
			*out_of_limits -= 1;
		new_node = create_stack(ft_atoi(split[i]), new_node);
		free(split[i]);
		i++;
	}
	free(split);
	return (new_node);
}
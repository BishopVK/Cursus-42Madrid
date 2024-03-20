/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:04:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/20 19:54:43 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void	no_repeat_numbers(int len)
{
	
} */

int	allowed_chars(char *argv, char *allowed)
{
	int		j;
	int		k;
	int		not_allowed_char;

	j = 0;
	not_allowed_char = 0;
	while (argv[j] != '\0')
	{
		k = 0;
		while (allowed[k] != '\0')
		{
			if (argv[j] != allowed[k])
				not_allowed_char++;
			else
			{
				not_allowed_char = 0;
				break ;
			}
			k++;
		}
		if (not_allowed_char != 0)
			return (not_allowed_char);
		j++;
	}
	return (not_allowed_char);
}

t_stack_node	*split_argvs(char *argv, int *total_strings,
					t_stack_node *new_node)
{
	int				j;
	char			**split;
	int				num_strings;

	split = ft_split(argv, ' '); // Realizar split a cada argumento
	num_strings = 0;
	while (split[num_strings] != NULL) // Contar cuántos elementos no nulos hay
		num_strings++;
	*total_strings += num_strings;
	j = 0;
	while (j < num_strings) // Imprimir las frases almacenadas
	{
		new_node = push(ft_atoi(split[j]), new_node);
		printf("split[%d]: %s\n", j, split[j]);
		j++;
	}
	j = 0;
	while (j < num_strings) // Liberar la memoria asignada a cada split
	{
		free(split[j]);
		j++;
	}
	free(split); // Liberar el array bidimensional
	return (new_node);
}

int	parse_argvs(int argc, char **argv, t_stack_node *new_node)
{
	int		i;
	int		not_allowed_char;
	char	*allowed;
	int		total_strings;

	allowed = ft_strdup("0123456789 +-");
	i = 1;
	while (i < argc)
	{
		not_allowed_char = allowed_chars(argv[i++], allowed);
		if (not_allowed_char != 0)
		{
			printf("Has introducido caracteres no permitidos\n");
			return (1);
		}
	}
	i = 1;
	while (i < argc)
		new_node = split_argvs(argv[i++], &total_strings, new_node);
	printf("total_strings = %d\n", total_strings);
	display(new_node);
	return (0);
}

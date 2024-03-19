/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:04:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/18 15:11:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	allowed_chars(char *argv, char *allowed)
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

static void	split_argvs(char *argv)
{
	int		j;
	char	**split;
	int		num_strings;

	split = ft_split(argv, ' '); // Realizar split a cada argumento
	num_strings = 0;
	while (split[num_strings] != NULL) // Contar cuántos elementos no nulos hay en frases
		num_strings++;
	j = 0;
	while (j < num_strings) // Imprimir las frases almacenadas
	{
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
}

int	parse_argvs(int argc, char **argv)
{
	int		i;
	int		not_allowed_char;
	char	*allowed;

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
		split_argvs(argv[i++]);
	return (0);
}
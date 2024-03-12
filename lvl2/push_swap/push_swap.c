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
int	main(int argc, char *argv[])
{
	int		i;
	int		all_quoted;
	char	*argument;
	char	**tokens;
	int		j;

	// Verificar si se proporcionaron al menos dos argumentos
	if (argc < 2)
	{
		ft_printf("Error: Debe proporcionar al menos un argumento.\n");
		return (1); // Devolver un código de error
	}

	// Verificar si todos los argumentos están entre comillas o ninguno lo está
	i = 1;
	all_quoted = 1;
	while (i < argc)
	{
		if (argv[i][0] != '"' || argv[i][ft_strlen(argv[i]) - 1] != '"')
		{
			all_quoted = 0;
			break ;
		}
		i++;
	}

	if (all_quoted)
	{
		// Si todos los argumentos están entre comillas, imprimir y procesar los valores
		i = 1;
		while (i < argc)
		{
			argument = argv[i];
			// Eliminar las comillas
			ft_memmove(argument, argument + 1, ft_strlen(argument));
			argument[ft_strlen(argument) - 1] = '\0';

			// Ahora, imprimir y procesar los valores separados por espacio
			tokens = ft_split(argument, ' ');
			if (tokens)
			{
				j = 0;
				while (tokens[j] != NULL)
				{
					ft_printf("%s\n", tokens[j]);
					free(tokens[j]); // Liberar memoria para cada token
					j++;
				}
				free(tokens); // Liberar memoria para el arreglo de tokens
			} else
			{
				// Manejar el caso en que ft_split devuelva NULL
				ft_printf("Error al dividir la cadena\n");
			}
			i++;
		}
	}
	else
	{
		// Si no todos los argumentos están entre comillas, imprimir y procesar todos los argumentos
		i = 1;
		while (i < argc)
		{
			ft_printf("%s\n", argv[i]);
			i++;
		}
	}
	return (0);
}
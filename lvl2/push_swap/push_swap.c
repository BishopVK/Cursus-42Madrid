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
/* int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main(int argc, char *argv[])
{
	int	numbers[MAX_NUMBERS];
	int	i;
	int	num;

	if (argc < 2)
	{
		ft_printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
		return (1);
	}

	if (argc - 1 > MAX_NUMBERS)
	{
		ft_printf("Se excedió el límite de %d números enteros.\n", MAX_NUMBERS);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		num = atoi(argv[i]);
		if (num == 0 && argv[i][0] != '0')
		{
			ft_printf("Error: '%s' no es un número entero válido.\n", argv[i]);
			return (1);
		}
		numbers[i - 1] = num;
		i++;
	}

	//qsort(numbers, argc - 1, sizeof(int), compare); // Ordenamos los números

	ft_printf("Números ordenados: ");
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d ", numbers[i]);
		i++;
	}
	ft_printf("\n");

	return (0);
} */

/* int	main(int argc, char *argv[])
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
			ft_printf("%s ", argv[i]);
			i++;
		}
	}
	return (0);
} */

int parse_input(char *argv[])
{
	int		i;
	int		j;
	char	**split;
	int		num_strings;


}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**split;
	int		num_strings;

	if (argc < 2)
	{
		ft_printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
		return (1);
	}
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			parse_input(*argv);
			split = ft_split(argv[i], ' '); // Realizar split a cada argumento
			num_strings = 0;
			while (split[num_strings] != NULL) // Contar cuántos elementos no nulos hay en frases
			{
				num_strings++;
			}
			j = 0;
			while (j < num_strings) // Imprimir las frases almacenadas
			{
				/* while (split[j] != '\0')
				{
					ft_strchr("0123456789+-", *split[j]);
					split[j]++;
				} */
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
			i++;
		}
	}
}
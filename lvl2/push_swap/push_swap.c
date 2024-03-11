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

int main(int argc, char *argv[]) {
	int all_quoted;
	int i;
	// Verificar si se proporcionaron al menos dos argumentos
	if (argc < 2) {
		printf("Error: Debe proporcionar al menos un argumento.\n");
		return (1); // Devolver un código de error
	}

	// Verificar si todos los argumentos están entre comillas o ninguno lo está
	all_quoted = 1;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '"' || argv[i][strlen(argv[i]) - 1] != '"')
		{
			all_quoted = 0;
			break;
		}
		i++;
	}

	if (all_quoted)
	{
		// Si todos los argumentos están entre comillas, imprimir y procesar los valores
		i = 1;
		while (i < argc)
		{
			char *argument = argv[i];
			// Eliminar las comillas
			memmove(argument, argument + 1, strlen(argument));
			argument[strlen(argument) - 1] = '\0';

			// Ahora, imprimir y procesar los valores separados por espacio
			char *token = strtok(argument, " ");
			while (token != NULL)
			{
				printf("%s\n", token);
				token = strtok(NULL, " ");
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
			printf("%s\n", argv[i]);
			i++;
		}
	}
	return (0);
}
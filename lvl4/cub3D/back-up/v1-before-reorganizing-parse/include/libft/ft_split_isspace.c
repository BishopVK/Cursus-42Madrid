/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_isspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:41 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/29 22:49:15 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Reserva (utilizando malloc(3)) un array de strings resultante de separar
//la string ’s’ en substrings utilizando el caracter ’c’ como delimitador.
//El array debe terminar con un puntero NULL.
static int	ft_count_elements(const char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (ft_isspace((unsigned char)s[i]))
			i++;
		if (s[i] != '\0')
			count++;
		while (!ft_isspace((unsigned char)s[i]) && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	free_split(char **split, int count)
{
	while (count > 0)
	{
		count--;
		free(split[count]);
	}
	free(split);
}

static char	**ft_copy_string(const char *s, char **split, int i)
{
	int	start;
	int	count;

	start = 0;
	count = 0;
	while (s[i])
	{
		while (ft_isspace((unsigned char)s[i]))
			(i)++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (!ft_isspace((unsigned char)s[i]) && s[i] != '\0')
			(i)++;
		split[count] = (char *)malloc((i - start + 1) * sizeof(char));
		if (!split[count])
		{
			free_split(split, count);
			return (NULL);
		}
		ft_strlcpy(split[count], s + start, i - start + 1);
		count++;
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split_isspace(char const *s)
{
	char	**split;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_count_elements(s);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!ft_copy_string(s, split, 0))
		return (NULL);
	return (split);
}

/* int	main(void)
{
	char const	*s = "     Hola    que	   	tal   \t    estás???";
	char		**split;
	int			i;
	int			numStrings = 0;

	i = 0;
	split = ft_split_isspace(s);

	// Contar cuántos elementos no nulos hay en frases
	while (split[numStrings] != NULL) {
		numStrings++;
	}

	// Imprimir el número de frases almacenadas
	printf("Número de frases almacenadas: %d\n", numStrings);

	// Imprimir las frases almacenadas
	for (int i = 0; i < numStrings; i++) {
		printf("split[%d]: %s\n", i, split[i]);
	}

	// Liberar la memoria asignada
	for (int i = 0; i < numStrings; i++) {
		free(split[i]);
	}

	free(split);

	return(0);
} */

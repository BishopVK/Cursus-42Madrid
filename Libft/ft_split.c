/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:06:55 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/18 12:44:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_count_elements(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**ft_copy_replace(const char *s, char c, char **split)
{
	int	i;
	int	start;
	int	count;

	i = 0;
	start = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		split[count] = (char *)malloc((i - start + 1) * sizeof(char));
		if (!split[count])
			return (NULL);
		ft_strlcpy(split[count], s + start, i - start + 1);
		count++;
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;

	count = ft_count_elements(s, c);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
	{
		free(split);
		return (NULL);
	}
	ft_copy_replace(s, c, split);
	split[count] = NULL;
	return (split);
}

/*int	main(void)
{
	char const	*s = "Hola,,,,,,,,,que,,,,tal";
	char		c = ',';
	char		**split;
	int			i;
	int			numStrings = 0;

	i = 0;
	split = ft_split(s, c);

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
}*/

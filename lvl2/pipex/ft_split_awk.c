/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_awk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:01:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/24 20:01:23 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static int	ft_count_elements(const char *s, char c)
{
	int		count;
	int		i;
	int		quote;

	count = 0;
	i = 0;
	quote = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		if (s[i] == '\'' && quote == 0)
			quote = 1;
		while ((s[i] != c && s[i] != '\0') || quote == 1)
		{
			i++;
			if (s[i] == '\'' && quote == 1)
				quote = 0;
		}
	}
	return (count);
}

static void	free_split_awk(char **split, int count)
{
	while (count > 0)
	{
		count--;
		free(split[count]);
	}
}

static int	find_string(int *i, char c, const char *s, int *quote)
{
	int	start;

	start = 0;
	while (s[*i] == c)
		(*i)++;
	if (s[*i] == '\0')
		return (start);
	start = *i;
	if (s[*i] == '\'' && *quote == 0)
		*quote = 1;
	while ((s[*i] != c && s[*i] != '\0') || *quote == 1)
	{
		(*i)++;
		if (s[*i] == '\'' && *quote == 1)
			*quote = 0;
	}
	return (start);
}

static char	**ft_copy_string(const char *s, char c, char **split)
{
	int	start;
	int	count;
	int	i;
	int	quote;

	start = 0;
	count = 0;
	i = 0;
	quote = 0;
	while (s[i])
	{
		start = find_string(&i, c, s, &quote);
		split[count] = (char *)malloc((i - start + 1) * sizeof(char));
		if (!split[count])
		{
			free_split_awk(split, count);
			return (NULL);
		}
		ft_strlcpy(split[count], s + start, i - start + 1);
		count++;
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split_awk(char const *s, char c)
{
	char	**split;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_count_elements(s, c);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!ft_copy_string(s, c, split))
	{
		free(split);
		return (NULL);
	}
	return (split);
}

// cc ft_split_awk.c libft/ft_strlcpy.c libft/ft_strlen.c
/* int	main(void)
{
	char const	*s = "awk -F',' '{suma += $2} END {print suma}' archivo.csv";
	char		c = ' ';
	char		**split;
	int			i;
	int			numStrings = 0;

	i = 0;
	split = ft_split_awk(s, c);

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

	return (0);
} */
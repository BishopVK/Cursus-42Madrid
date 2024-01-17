/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:06:55 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/17 15:01:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char    **ft_split(char const *s, char c)
{
    char    **split;
    int        i;
    int        count;
    int        j;
    
    i = 0;
    count = 0;
    while (s[i] != '\0')
        if (s[i++] == c)
            count++;
    split = (char **)malloc((count + 2) * sizeof(char *));
    if (!split)
    {
        free(split);
        return (NULL);
    }
    i = 0;
    j = 0;
    while (i <= count)
    {
        split[i] = (char *)malloc(((ft_strchr(s, c) - s) - j + 1) * sizeof(char));
        while (i < ft_strchr(s, c) - s)
            ft_strlcpy(split[i], s, (ft_strchr(s, c) - s + 1));
        i++;
        split[i]
    }
    split[count] = '\0';
    return (split);
}

int	main(void)
{
	char const	*s = "Hola,que,tal";
	char		c = ',';
	char		**split;
	int			i;
    int			numStrings = 0;

	split = ft_split(s, c);

	// Contar cuántos elementos no nulos hay en frases
    while (split[numStrings] != NULL) {
        numStrings++;
    }

    // Imprimir el número de frases almacenadas
    printf("Número de frases almacenadas: %d\n", numStrings);

	// Imprimir las frases almacenadas
    for (int i = 0; i < 3; i++) {
        printf("split[%d]: %s\n", i, split[i]);
    }

    // Liberar la memoria asignada
    for (int i = 0; i < 3; i++) {
        free(split[i]);
    }
    
	free(split);

	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:47:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/12 12:24:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	s += len -1;
	while (len--)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "En un lugar de la mancha";
	char	character = 'N';
	char	*pos = ft_strrchr(str, character);

	printf("Cadena: %s\n", str);
	if (pos != NULL)
		printf("Se encontró el caracter '%c' en la posición %ld\n",
			character, pos - str);
	else
		printf("No se encontró el caracter '%c' en la cadena\n", character);
	return (0);
}*/

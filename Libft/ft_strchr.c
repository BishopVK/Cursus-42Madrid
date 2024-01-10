/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:26:21 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/10 21:10:03 by bishopvk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "En un lugar de la mancha";
	char	character = 'a';
	char	*pos = ft_strchr(str, character);

	printf("Cadena: %s\n", str);
	if (pos != NULL)
		printf("Se encontró el caracter '%c' en la posición %ld\n",
			character, pos - str);
	else
		printf("No se encontró el caracter '%c' en la cadena\n", character);
	return (0);
}*/

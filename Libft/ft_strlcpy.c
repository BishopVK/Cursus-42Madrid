/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:05:02 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/12 10:49:25 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclength;
	size_t	i;

	srclength = 0;
	while (src[srclength] != '\0')
		srclength++;
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclength);
}

/*int	main(void)
{
	char			src[] = "Hola Caracola!";
	char			dest[20];
	unsigned int	srclength;


	srclength = ft_strlcpy(dest, src, 20);
	printf("Cadena de destino: %s\n", dest);
	printf("El tamaño de la cadena de origen: %u\n", srclength);
	return (0);
}*/

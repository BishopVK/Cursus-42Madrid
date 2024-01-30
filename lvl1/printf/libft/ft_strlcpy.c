/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:06:18 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:37:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copia una cadena a un buffer con un límite máximo,
//evitando desbordamientos de buffer.
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:55:19 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/07 13:55:19 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Busca la primera aparición de un carácter en una cadena.
char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

//Calcula la longitud de una cadena de caracteres
//(sin incluir el carácter nulo).
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

//Copia un bloque de memoria desde una ubicación de origen
//a una ubicación de destino, manejando superposiciones de memoria.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (dst_tmp < src_tmp || dst_tmp >= (src_tmp + len))
	{
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	else
	{
		dst_tmp += len - 1;
		src_tmp += len - 1;
		while (len--)
			*dst_tmp-- = *src_tmp--;
	}
	return (dst);
}

//Rellena un bloque de memoria con un valor específico.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = b;
	i = 0;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (b);
}
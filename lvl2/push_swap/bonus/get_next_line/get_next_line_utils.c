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
	if (s == NULL)
		return (NULL);
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

	if (!str)
		return (0);
	if (str == NULL)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

//Duplica una cadena de caracteres en una nueva ubicación de memoria,
//asignando dinámicamente espacio suficiente
//y copiando el contenido de la cadena original.
char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*principio;

	if (!s)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	principio = dest;
	while (*s != '\0')
		*dest++ = *s++;
	*dest = '\0';
	return (principio);
}

//Reserva (con malloc(3)) y devuelve una nueva string,
//formada por la concatenación de ’s1’ y ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

//Copia una cadena a un buffer con un límite máximo,
//evitando desbordamientos de buffer.
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (src == NULL)
		return (0);
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

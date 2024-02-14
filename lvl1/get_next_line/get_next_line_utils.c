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

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

//Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
//La substring empieza desde el índice ’start’ y tiene una longitud máx. ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		if (sub != NULL)
			sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (sub != NULL)
	{
		i = 0;
		while (i < len && s[start])
			sub[i++] = s[start++];
		sub[i] = '\0';
	}
	return (sub);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*principio;

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
/* char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	i = 0;
	//if (s1 == NULL && s2 == NULL)
	//	return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1 != NULL)
		while (*s1)
			result[i++] = *s1++;
	if (s2 != NULL)
		while (*s2)
			result[i++] = *s2++;
	result[i] = '\0';
	return (result);
} */

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
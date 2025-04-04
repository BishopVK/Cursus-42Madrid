/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_isspace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:07:01 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/02 17:40:48 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Elimina todos los espacios de la string ’set’ desde el principio y desde
//el final de ’s1’, hasta encontrar un caracter no perteneciente a ’isspace’.
//La string resultante se devuelve con una reserva de malloc(3)
char	*ft_strtrim_isspace(char const *s1)
{
	char	*result;
	size_t	start;
	size_t	end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isspace((unsigned char)s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_isspace((unsigned char)s1[end]))
		end--;
	result = (char *)malloc((end - start + 2) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}

/* int	main(void)
{
	char const 	*s1 = "    HOLA MUNDO    ";
	printf("Franse original: %s\n", s1);
	printf("Longitud: %li\n", ft_strlen(s1));

	char 		*result = ft_strtrim_isspace(s1);

	printf("Franse resultante: %s\n", result);
	printf("Longitud: %li\n", ft_strlen(result));

	free (result);
	return (0);
} */

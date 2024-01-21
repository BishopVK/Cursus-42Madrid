/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:43:09 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/21 13:43:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	my_function(unsigned int n, char c)
{
	(void)n;
	if (c >= 'a' && c <= 'z')
		return ((char)(c - 'a' + 'A'));
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*int	main(void)
{
	char const	*s = "abcdefghijklmnñopqrstuvwxyz,ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
	char	*result;

	result = ft_strmapi(s, my_function);

	if (result != NULL)
	{
		printf("Resultado: %s\n", result);
		free(result);
	}
	else
		printf("Fallo en la reserva de memoria\n");
	return (0);
}*/
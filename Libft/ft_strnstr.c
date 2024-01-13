/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:33:25 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/12 17:50:47 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
int	i;
	int	j;
	int	k;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		k = i;
		while (needle[j] != '\0' && haystack[k] == needle[j])
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	cadena[] = "Hola, Mundo!!";
	char	subcadena[] = "";

	printf("%s\n", ft_strnstr(cadena, subcadena, 5));
	return (0);
}*/

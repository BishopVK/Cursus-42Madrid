/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bishopvk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:59:36 by bishopvk          #+#    #+#             */
/*   Updated: 2024/01/16 13:41:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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

/*int	main(void)
{
	char	*original = "Hello, World!";
	//char	*duplicate = ft_strdup(original);
	char	*duplicate = ft_strdup(((void *)0));

	if (duplicate != NULL)
	{
		printf("Original: %s\n", original);
		printf("Duplicate: %s\n", duplicate);
		free(duplicate);
	}
	else
		fprintf(stderr, "Error: No se pudo duplicar la cadena\n");
	return (0);
}*/

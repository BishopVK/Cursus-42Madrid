/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:09:22 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/17 14:25:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*principio;

	dest = (char *)malloc(strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	principio = dest;
	while (*s != '\0')
		*dest++ = *s++;
	*dest = '\0';
	return (principio);
}

void ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	atexit(ft_leaks);
	const char	*s = "HOLA";
	char		*dst;

	dst = ft_strdup(s);

	printf("Origen %s\n", s);
	printf("Destino %s\n", dst);

	//free(dst);
	return (0);
}
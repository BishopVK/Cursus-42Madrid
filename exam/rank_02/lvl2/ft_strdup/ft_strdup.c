/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:13:17 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 12:29:16 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	if (!src)
		return (NULL);
	dst = (char *)malloc(ft_strlen(src) + 1);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src;
	char	*dst;
	char	*dst2;


	src = "HOLA!!";
	dst = ft_strdup(src);
	dst2 = strdup(src);
	printf("mi dst = %s\n", dst);
	printf("original dst2 = %s\n", dst2);
	free(dst);
	free(dst2);
	return (0);
} */
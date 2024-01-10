/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:21:11 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/10 21:06:12 by bishopvk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}

/*int	main(void)
{
	char	str[] = "En un lugar de la mancha";

	printf("Antes: %s\n", str);
	bzero(str, 10);
	printf("Después: %s\n", str);
	return (0);
}*/

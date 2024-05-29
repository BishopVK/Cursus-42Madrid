/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:30:33 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 14:28:41 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;

	if (!s1 || !s2)
		return (NULL);
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}

#include <string.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*dst1;
	char	*dst2;

	s1 = "Hola caracola";
	s2 = "cr";
	dst1 = ft_strpbrk(s1, s2);
	dst2 = strpbrk(s1, s2);
	dst1 = ft_strpbrk(s1, s2);
	printf("mi dst1 = %s\n", dst1);
	printf("original dst2 = %s\n", dst2);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:02:48 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/14 00:23:16 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	u_s1;
	unsigned char	u_s2;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		u_s1 = (unsigned char)s1[i];
		u_s2 = (unsigned char)s2[i];
		if (u_s1 != u_s2)
			return (u_s1 - u_s2);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	str1[] = "abcdef";
	char	str2[] = "abzdef";
	printf("Función original: %i\n", ft_strncmp(str1, str2, 3));
	printf("Función ft_strncmp: %i\n", ft_strncmp(str1, str2, 3));
}*/
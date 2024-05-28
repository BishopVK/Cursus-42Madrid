/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:44:28 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 10:58:04 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/* #include <stdio.h>

int	main(void)
{
	char	*src = "Hola mundo!";
	char	dst[20];
	char	*result;

	result = ft_strcpy(dst, src);
	printf("dst = %s\n", result);
	return (0);
} */
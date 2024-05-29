/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:25:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 11:34:29 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	int		result;

	s1 = "holaa";
	s2 = "hola";

	result = ft_strcmp(s1, s2);
	printf("mi result = %i\n", result);

	result = strcmp(s1, s2);
	printf("original result = %i\n", result);
	return (0);
} */

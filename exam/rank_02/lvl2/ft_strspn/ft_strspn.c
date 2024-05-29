/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:00:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 15:17:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int		i;
	int		j;
	size_t	result;
	int		flag;

	if (!s || !accept)
		return (0);
	i = 0;
	result = 0;
	while (s[i])
	{
		j = 0;
		flag = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				flag++;
			j++;
		}
		if (flag == 0)
			return (result);
		result++;
		i++;
	}
	return (result);
}

/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	*s;
	const char	*accept;
	size_t		result;

	s = "Hola caracola";
	accept = "Hola cr";
	result = strspn(s, accept);
	printf("result original = %zu\n", result);
	result = ft_strspn(s, accept);
	printf("mi result = %zu\n", result);
	return (0);
} */
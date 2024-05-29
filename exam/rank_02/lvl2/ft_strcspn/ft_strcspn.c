/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:54:34 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 12:09:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int		i;
	int		j;
	size_t	size;

	if (!s || !reject)
		return (0);
	i = 0;
	size = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (size);
			j++;
		}
		size++;
		i++;
	}
	return (size);
}
/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	size_t		size;
	const char	*s;
	const char	*reject;

	s = "Hola caracola";
	reject = "le";
	size = strcspn(s, reject);
	printf("original size = %zu\n", size);
	size = ft_strcspn(s, reject);
	printf("mi size = %zu\n", size);
	return (0);
} */
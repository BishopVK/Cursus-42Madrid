/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:56:08 by danjimen &        #+#    #+#             */
/*   Updated: 2025/03/29 22:48:45 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Busca la primera aparición de un carácter en una cadena.
size_t	*ft_strcspn(const char *s, const char *reject)
{
	const char	*p;
	const char	*spanp;
	char		c;
	char		sc;

	p = s;
	c = *p;
	while (c != '\0')
	{
		spanp = reject;
		sc = *spanp;
		while (sc != '\0')
		{
			if (sc == c)
				return (p - 1 - s);
			sc = *spanp++;
		}
		c = *p++;
	}
	return (p - 1 - s);
}

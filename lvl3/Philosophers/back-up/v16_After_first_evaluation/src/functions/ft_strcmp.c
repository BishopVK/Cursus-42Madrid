/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:31:09 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/16 18:34:36 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

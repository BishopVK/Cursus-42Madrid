/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:51:58 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 20:07:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	int	biggest;
	int	i;

	if (tab[0] == '\0')
		return (0);
	biggest = tab[0];
	i = 0;
	while (len)
	{
		if (tab[i] > biggest)
			biggest = tab[i];
		i++;
		len--;
	}
	return (biggest);
}

#include <stdio.h>

int	main(void)
{
	int	array[] = {4, 12, 0, 18, 42, 1, 3, 35};
	int	result;

	result = max(array, 8);
	printf("result = %i\n", result);
	return (0);
}
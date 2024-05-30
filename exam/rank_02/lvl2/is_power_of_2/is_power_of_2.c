/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:14:43 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 19:27:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	unsigned int	nbr;

	nbr = 2;
	while (nbr < n)
	{
		nbr *= 2;
	}
	if (nbr == n)
		return (1);
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	unsigned int	nbr;
	unsigned int	result;

	nbr = 1024;
	result = is_power_of_2(nbr);
	if (result == 1)
		printf("%u es una potencia de 2\n", nbr);
	else
		printf("%u NO es una potencia de 2\n", nbr);
	return (0);
} */
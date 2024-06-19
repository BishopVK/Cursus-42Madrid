/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:35:41 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/19 09:53:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_its_prime(int nbr)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i <= nbr)
	{
		if ((nbr % i) == 0)
			count++;
		i++;
	}
	return (count);
}

void	ft_generate_primes(int	*nbr)
{
	int	i;

	i = 2;
	while (i <= *nbr)
	{
		if (ft_its_prime(i) == 2)
		{
			if ((*nbr % i) == 0)
			{
				printf("%i", i);
				if (*nbr != i)
					printf("*");
				*nbr = *nbr / i;
				ft_generate_primes(nbr);
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	prime;
	int	nbr;

	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		prime = ft_its_prime(nbr);
		if (prime == 2 || nbr == 1)
			printf("%d", nbr);
		else
			ft_generate_primes(&nbr);
	}
	printf("\n");
	return (0);
}

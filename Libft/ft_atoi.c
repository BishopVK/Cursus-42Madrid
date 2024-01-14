/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:12:45 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/14 18:54:13 by bishopvk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nb;

	sign = 1;
	while (*nptr && (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r')))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (nb * sign);
}

/*int	main(void)
{
	int	resultado;

	resultado = ft_atoi("   -21474ab83645");
	printf("Resultado = %d\n", resultado);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:43:19 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/24 21:37:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Convierte una cadena de caracteres que representa
//un número en un largo (long).
long	ft_atol(const char *nptr)
{
	long	sign;
	long	nb;

	sign = 1;
	while (*nptr && (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r')))
		nptr++;
	while (*nptr == '+' || *nptr == '-') {
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (nb * sign);
}

/* int	main(void)
{
	long	resultado;

	resultado = ft_atol("   -2147483648");
	printf("Resultado = %ld\n", resultado);
	if (resultado < INT_MIN || resultado > INT_MAX)
		printf("El nº %ld está fuera de los límites de INT\n", resultado);
	return (0);
} */

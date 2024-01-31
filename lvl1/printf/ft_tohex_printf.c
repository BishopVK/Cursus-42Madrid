/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:38:59 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/31 19:38:59 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_tohex_printf(unsigned int n, char *format, size_t *counter)
{
	if (n == 0)
		ft_putchar_printf('0', counter);
	/* else if (n < 0)
	{
		ft_putchar_printf('-', counter);
		ft_tohex_printf(-n, format, counter);
	} */
	else
	{
		if (n >= 16)
			ft_tohex_printf((n / 16), format, counter);
		if ((n % 16) < 10)
			ft_putchar_printf((n % 16) + '0', counter);
		else
		{
			if (*format == 'x')
				ft_putchar_printf((n % 16) - 10 + 'a', counter);
			else
				ft_putchar_printf((n % 16) - 10 + 'A', counter);
		}
	}
}
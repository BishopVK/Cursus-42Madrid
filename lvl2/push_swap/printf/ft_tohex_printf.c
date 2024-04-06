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

#include "ft_printf.h"

int	ft_tohex_printf(unsigned long n, char *format, size_t *counter)
{
	int	write_error;

	if (n == 0)
		write_error = ft_putchar_printf('0', counter);
	else
	{
		if (n >= 16)
			ft_tohex_printf((n / 16), format, counter);
		if ((n % 16) < 10)
			write_error = ft_putchar_printf((n % 16) + '0', counter);
		else
		{
			if (*format == 'X')
				write_error = ft_putchar_printf((n % 16) - 10 + 'A', counter);
			else
				write_error = ft_putchar_printf((n % 16) - 10 + 'a', counter);
		}
	}
	return (write_error);
}

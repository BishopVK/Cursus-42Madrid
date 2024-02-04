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

void	ft_tohex_printf(unsigned long n, char *format, size_t *counter,
			int *write_error)
{
	if (*write_error < 0)
		return ;
	if (n == 0)
		ft_putchar_printf('0', counter, write_error);
	else
	{
		if (n >= 16)
			ft_tohex_printf((n / 16), format, counter, write_error);
		if ((n % 16) < 10)
			ft_putchar_printf((n % 16) + '0', counter, write_error);
		else
		{
			if (*format == 'X')
				ft_putchar_printf((n % 16) - 10 + 'A', counter, write_error);
			else
				ft_putchar_printf((n % 16) - 10 + 'a', counter, write_error);
		}
	}
}

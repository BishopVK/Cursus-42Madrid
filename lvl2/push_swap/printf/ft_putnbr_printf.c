/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/06 16:02:24 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int n, size_t *counter)
{
	int	write_error;

	if (n == -2147483648)
	{
		ft_putnbr_printf((n / 10), counter);
		write_error = ft_putchar_printf('8', counter);
	}
	else if (n < 0)
	{
		write_error = ft_putchar_printf('-', counter);
		ft_putnbr_printf(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr_printf((n / 10), counter);
		write_error = ft_putchar_printf((n % 10) + '0', counter);
	}
	return (write_error);
}

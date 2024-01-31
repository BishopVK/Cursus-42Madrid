/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/31 21:22:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_printf(int n, size_t *counter)
{
	if (n == -2147483648)
	{
		ft_putnbr_printf((n / 10), counter);
		ft_putchar_printf('8', counter);
	}
	else if (n < 0)
	{
		ft_putchar_printf('-', counter);
		ft_putnbr_printf(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr_printf((n / 10), counter);
		ft_putchar_printf((n % 10) + '0', counter);
	}
}

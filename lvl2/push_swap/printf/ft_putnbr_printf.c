/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/02 11:06:31 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int n, size_t *counter, int *write_error)
{
	if (*write_error < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putnbr_printf((n / 10), counter, write_error);
		ft_putchar_printf('8', counter, write_error);
	}
	else if (n < 0)
	{
		ft_putchar_printf('-', counter, write_error);
		ft_putnbr_printf(-n, counter, write_error);
	}
	else
	{
		if (n > 9)
			ft_putnbr_printf((n / 10), counter, write_error);
		ft_putchar_printf((n % 10) + '0', counter, write_error);
	}
}

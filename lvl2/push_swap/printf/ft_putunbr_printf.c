/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:10:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/31 20:10:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_printf(unsigned int n, size_t *counter)
{
	int	write_error;

	if (n >= 10)
		ft_putunbr_printf((n / 10), counter);
	write_error = ft_putchar_printf(((n % 10) + '0'), counter);
	return (write_error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:50:24 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/06 16:04:18 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(char c, size_t *counter)
{
	int	write_error;

	write_error = write(1, &c, 1);
	if (write_error < 0)
		return (write_error);
	(*counter)++;
	return (write_error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:43:49 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/31 19:43:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf(char *str, size_t *counter)
{
	char	*null;
	int		write_error;

	null = "(null)";
	if (!str)
		str = null;
	while (*str)
	{
		write_error = ft_putchar_printf(*str, counter);
		if (write_error < 0)
			return (write_error);
		str++;
	}
	return (write_error);
}

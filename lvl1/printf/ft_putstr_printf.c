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

void	ft_putstr_printf(char *str, size_t *counter, int *write_error)
{
	char	*null;

	if (*write_error < 0)
		return ;
	null = "(null)";
	if (!str)
		str = null;
	while (*str)
	{
		ft_putchar_printf(*str, counter, write_error);
		if (*write_error < 0)
			return ;
		str++;
	}
}

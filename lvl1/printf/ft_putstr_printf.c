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

void	ft_putstr_printf(char *str, size_t *counter)
{
	char	*null;

	null = "(null)";
	if (!str)
	{
		ft_putstr_printf(null, counter);
		return ;
	}
	while (*str)
	{
		ft_putchar_printf(*str, counter);
		str++;
	}
}

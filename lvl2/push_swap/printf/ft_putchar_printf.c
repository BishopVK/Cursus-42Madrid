/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:50:24 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/12 17:40:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(char c, size_t *counter, int *write_error)
{
	int	wr_er;

	wr_er = write(1, &c, 1);
	if (wr_er < 0)
	{
		(*write_error) = -1;
		return ;
	}
	(*counter)++;
}

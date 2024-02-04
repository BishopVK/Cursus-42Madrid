/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:09:47 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/02 09:35:10 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_putchar_printf(char c, size_t *counter, int *write_error);
void	ft_putnbr_printf(int n, size_t *counter, int *write_error);
void	ft_putstr_printf(char *str, size_t *counter, int *write_error);
void	ft_putunbr_printf(unsigned int n, size_t *counter, int *write_error);
void	ft_tohex_printf(unsigned long n, char *format, size_t *counter,
			int *write_error);

#endif
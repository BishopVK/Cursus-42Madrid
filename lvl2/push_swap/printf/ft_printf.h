/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:09:47 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/06 16:41:45 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//va_list, va_start, va_arg, va_end
# include <stdarg.h>

//printf
# include <stdio.h>

//write
# include <unistd.h>

int	ft_printf(char const *format, ...);
int	ft_putchar_printf(char c, size_t *counter);
int	ft_putnbr_printf(int n, size_t *counter);
int	ft_putstr_printf(char *str, size_t *counter);
int	ft_putunbr_printf(unsigned int n, size_t *counter);
int	ft_tohex_printf(unsigned long n, char *format, size_t *counter);

#endif
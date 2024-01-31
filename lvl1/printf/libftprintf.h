/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:50:32 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/31 22:40:07 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_putchar_printf(char c, size_t *size);
void	ft_putnbr_printf(int n, size_t *counter);
void	ft_putstr_printf(char *str, size_t *counter);
void	ft_putunbr_printf(unsigned int n, size_t *counter);
void	ft_tohex_printf(unsigned int n, char *format, size_t *counter);

#endif
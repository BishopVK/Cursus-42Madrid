/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:07:15 by danjimen          #+#    #+#             */
/*   Updated: 2024/11/01 09:37:04 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

static void	ft_putstr(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		(*count)++;
		str++;
	}
}

static void	ft_putnbr(int n, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putstr("-", count);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}

static void	ft_puthex(unsigned int n, int *count)
{
	char	*hex = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16, count);
	write(1, &hex[n % 16], 1);
	(*count)++;
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (*format == 'd')
				ft_putnbr(va_arg(args, int), &count);
			else if (*format == 'x')
				ft_puthex(va_arg(args, unsigned int), &count);
			else
			{
				write(1, format, 1);
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	*str = "Hello World!";
	int		nbr = 42;
	int		hex = 255;
	int		count;

	count = ft_printf("str = %s | nbr = %d | hex = %x\n", str, nbr, hex);
	ft_printf("count = %d\n", count);
	count = printf("str = %s | nbr = %d | hex = %x\n", str, nbr, hex);
	printf("count = %d\n", count);
	return (0);
}
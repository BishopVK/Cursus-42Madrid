/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:41:44 by bishopvk          #+#    #+#             */
/*   Updated: 2024/10/30 20:04:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static void ft_putstr(char *str, int *count)
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
	c= (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}

static void	ft_puthex(unsigned int n, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16, count);
	write(1, &hex[n % 16], 1);
	(*count)++;
}

int	ft_printf(const char *format, ... )
{
	va_list	args;
	int		count;

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
	int		count;
	char	*str = "hola";
	int		nbr = 42;
	int		hex = 255;

	count = ft_printf("str = %s | int = %d | hex = %x\n", str, nbr, hex);
	ft_printf("count = %d\n", count);
	count = printf("str = %s | int = %d | hex = %x\n", str, nbr, hex);
	printf("count = %d\n", count); 
	return (0);
}



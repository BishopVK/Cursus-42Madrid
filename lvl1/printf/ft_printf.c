/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:17:43 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/31 20:15:14 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <unistd.h>

static void	ft_detect_format(va_list args, char *format, size_t *counter)
{
	if (*format == 'c')
		ft_putchar_printf(va_arg(args, int), counter);
	else if (*format == 'i' || *format == 'd')
		ft_putnbr_printf(va_arg(args, int), counter);
	else if (*format == '%')
		ft_putchar_printf('%', counter);
	else if (*format == 's')
		ft_putstr_printf(va_arg(args, char *), counter);
	else if (*format == 'u')
		ft_putunbr_printf(va_arg(args, unsigned int), counter);
	/* else if (*format == 'p')
		ft_tohex_printf(va_arg(args, int), format, counter);
	else if (*format == 'x')
		ft_tohex_printf(va_arg(args, int), format, counter);
	else if (*format == 'X')
		ft_tohex_printf(va_arg(args, int), format, counter);
	else
		ft_putchar_printf(*format, counter); */
}

int	ft_printf(char const *format, ...)
{
	size_t	counter;
	va_list	args;

	if (!format)
		return (0);
	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_detect_format(args, (char *)format, &counter);
		}
		else
			ft_putchar_printf(*format, &counter);
		format++;
	}
	va_end(args);
	return (counter);
}
//cc -Wall -Wextra -Werror *.c && ./a.out && rm a.out
int	main(void)
{
	int	size;

	char	c = 'D';
	printf("CARACTER (c):\n");
	printf("Printf: %c\n", c);
	size = ft_printf("ft_printf: %c\n", c);
	printf("Size: %d\n", size);

	int		n = -123;
	printf("\nNÚMERO ENTERO (i):\n");
	printf("Printf: %i\n", n);
	size = ft_printf("ft_printf: %i\n", n);
	printf("Size: %i\n", size);

	printf("\nNÚMERO ENTERO (d):\n");
	printf("Printf: %d\n", n);
	size = ft_printf("ft_printf: %d\n", n);
	printf("Size: %d\n", size);

	unsigned int	ui = 42;
	printf("\nUNSIGNED INT (u):\n");
	printf("Printf: %u\n", ui);
	size = ft_printf("ft_printf: %u\n", ui);
	printf("Size: %d\n", size);

	printf("\nPORCENTAJE (%%):\n");
	printf("Printf: %%\n");
	size = ft_printf("ft_printf: %%\n");
	printf("Size: %d\n", size);

	char	*s = "Hola Mundo!";
	printf("\nSTRING (s):\n");
	printf("Printf: %s\n", s);
	size = ft_printf("ft_printf: %s\n", s);
	printf("Size: %d\n", size);

	char *p = "456";
	printf("\nPUNTEROS (p):\n");
	printf("Printf: %p\n", p);
	//size = ft_printf("ft_printf: %%\n");
	//printf("Size: %d\n", size);

	int	x = 123;
	printf("\nHEXADECIMAL EN MINÚSCULAS (x):\n");
	printf("Printf: %x\n", x);
	//size = ft_printf("ft_printf: %%\n");
	//printf("Size: %d\n", size);

	int	xx = 123;
	printf("\nHEXADECIMAL EN MAYÚSCULAS (X):\n");
	printf("Printf: %X\n", xx);
	//size = ft_printf("ft_printf: %%\n");
	//printf("Size: %d\n", size);

	//printf("");
	//size = ft_printf("");
	//printf("Size: %d", size);

	return (0);
}

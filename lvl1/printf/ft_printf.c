/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:17:43 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/04 23:06:10 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>

static void	ft_detect_format(va_list args, char *format,
	size_t *counter, int *write_error)
{
	if (*write_error < 0)
		return ;
	if (*format == 'c')
		ft_putchar_printf(va_arg(args, int), counter, write_error);
	else if (*format == 'i' || *format == 'd')
		ft_putnbr_printf(va_arg(args, int), counter, write_error);
	else if (*format == '%')
		ft_putchar_printf('%', counter, write_error);
	else if (*format == 's')
		ft_putstr_printf(va_arg(args, char *), counter, write_error);
	else if (*format == 'u')
		ft_putunbr_printf(va_arg(args, unsigned long), counter, write_error);
	else if (*format == 'x' || *format == 'X')
		ft_tohex_printf((unsigned long)va_arg(args, unsigned int),
			format, counter, write_error);
	else if (*format == 'p')
	{
		ft_putchar_printf('0', counter, write_error);
		ft_putchar_printf('x', counter, write_error);
		ft_tohex_printf((unsigned long)(unsigned long)va_arg(args, void *),
			format, counter, write_error);
	}
	else
		(*write_error) = -1;
}

int	ft_printf(char const *format, ...)
{
	size_t	counter;
	va_list	args;
	int		write_error;

	write_error = 0;
	if (!format)
		return (0);
	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_detect_format(args, (char *)format, &counter, &write_error);
			return ((write_error < 0) && -1);
		}
		else
			ft_putchar_printf(*format, &counter, &write_error);
		return ((write_error < 0) && -1);
		format++;
	}
	va_end(args);
	return (counter);
}
//cc -Wall -Wextra -Werror *.c && ./a.out && rm a.out
/* int	main(void)
{
	int	size;

	char	c = 'D';
	printf("\nCARACTER (c):\n");
	size = printf("Printf: %c\n", c);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %c\n", c);
	printf("Size ft_printf: %d\n", size);

	int		n = -123;
	printf("\nNÚMERO ENTERO (i):\n");
	size = printf("Printf: %i\n", n);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %i\n", n);
	printf("Size ft_printf: %d\n", size);

	printf("\nNÚMERO ENTERO (d):\n");
	size = printf("Printf: %d\n", n);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %d\n", n);
	printf("Size ft_printf: %d\n", size);

	unsigned int	ui = 42;
	printf("\nUNSIGNED INT (u):\n");
	size = printf("Printf: %u\n", ui);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %u\n", ui);
	printf("Size ft_printf: %d\n", size);

	printf("\nPORCENTAJE (%%):\n");
	size = printf("Printf: %%\n");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %%\n");
	printf("Size ft_printf: %d\n", size);

	char	*s = "Hola Mundo!";
	printf("\nSTRING (s):\n");
	size = printf("Printf: %s\n", s);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %s\n", s);
	printf("Size ft_printf: %d\n", size);

	char	*sn = NULL;
	printf("\n>>STRING NULL (s):\n");
	size = printf("%s\n", sn);
	printf("Size Printf: %d\n", size);
	size = ft_printf("%s\n", sn);
	printf("Size ft_printf: %d\n", size);

	int *p = &n;
	printf("\nPUNTEROS (p):\n");
	size = printf("Printf: %p\n", (void *)p);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %p\n", (void *)p);
	printf("Size ft_printf: %d\n", size);

	unsigned int	x = -1;
	printf("\nHEXADECIMAL EN MINÚSCULAS (x):\n");
	size = printf("Printf: %x\n", x);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %x\n", x);
	printf("Size ft_printf: %d\n", size);

	unsigned int	xx = -1;
	printf("\nHEXADECIMAL EN MAYÚSCULAS (X):\n");
	size = printf("Printf: %X\n", xx);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %X\n", xx);
	printf("Size ft_printf: %d\n", size);

	printf("\nVACÍO:\n");
	size = printf("");
	printf("Size Printf: %d\n", size);
	size = ft_printf("");
	printf("Size ft_printf: %d\n", size);

	printf("\nCONVERSIÓN ERRONEA:\n");
	//size = printf("Printf: %r\n", n);
	//printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %r\n", n);
	printf("Size ft_printf: %d\n", size);

	printf("\nNO IMPRIMIBLES:\n");
	size = printf("Printf: \001\002\007\v\010\f\r\n");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: \001\002\007\v\010\f\r\n");
	printf("Size ft_printf: %d\n", size);

	return (0);
} */

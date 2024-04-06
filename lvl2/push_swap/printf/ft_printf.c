/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:17:43 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/06 16:40:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_detect_format(va_list args, char *format, size_t *counter)
{
	int	write_error;

	if (*format == 'c')
		write_error = ft_putchar_printf(va_arg(args, int), counter);
	else if (*format == 'i' || *format == 'd')
		write_error = ft_putnbr_printf(va_arg(args, int), counter);
	else if (*format == '%')
		write_error = ft_putchar_printf('%', counter);
	else if (*format == 's')
		write_error = ft_putstr_printf(va_arg(args, char *), counter);
	else if (*format == 'u')
		write_error = ft_putunbr_printf(va_arg(args, unsigned long), counter);
	else if (*format == 'x' || *format == 'X')
		write_error = ft_tohex_printf((unsigned long)va_arg(args, unsigned int),
				format, counter);
	else if (*format == 'p')
	{
		write_error = ft_putchar_printf('0', counter);
		write_error = ft_putchar_printf('x', counter);
		write_error = ft_tohex_printf((unsigned long)(unsigned long)va_arg
				(args, void *), format, counter);
	}
	else
		write_error = -1;
	return (write_error);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	counter;
	int		write_error;

	if (!format)
		return (0);
	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			write_error = ft_detect_format(args, (char *)format, &counter);
		}
		else
			write_error = ft_putchar_printf(*format, &counter);
		if (write_error < 0)
			return (-1);
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
	printf("\nSTRING NULL (s):\n");
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

	printf("\nPUNTERO VACÍO(p):\n");
	size = printf("Printf: %p\n", "");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %p\n", "");
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
	//size = printf("");
	//printf("Size Printf: %d\n", size);
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

	printf("\nMÚLTIPLES CONVERSIONES:\n");
	size = printf("Printf: int = %i, char = %c, str = %s, hex = %x\n",
		n, c, s, x);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: int = %i, char = %c, str = %s, hex = %x\n",
		n, c, s, x);
	printf("Size ft_printf: %d\n", size);

	return (0);
} */

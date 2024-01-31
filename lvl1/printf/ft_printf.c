/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:17:43 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/31 15:07:29 by danjimen         ###   ########.fr       */
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

int	main(void)
{
	int	size;
	// Prueba de caracteres
	char	c = 'D';
	int		n = -123;
	printf("CARACTER (c):\n");
	printf("Printf: %c\n", c);
	size = ft_printf("ft_printf: %c\n", c);
	printf("Size: %d\n", size);

	printf("\nNÚMERO ENTERO (i):\n");
	printf("Printf: %i\n", n);
	size = ft_printf("ft_printf: %i\n", n);
	printf("Size: %i\n", size);

	printf("\nNÚMERO ENTERO (d):\n");
	printf("Printf: %d\n", n);
	size = ft_printf("ft_printf: %d\n", n);
	printf("Size: %d\n", size);

	printf("\nPORCENTAJE (%%):\n");
	printf("Printf: %%\n");
	size = ft_printf("ft_printf: %%\n");
	printf("Size: %d\n", size);

	/* printf("");
	size = ft_printf("");
	printf("Size: %d", size); */

	return (0);
}

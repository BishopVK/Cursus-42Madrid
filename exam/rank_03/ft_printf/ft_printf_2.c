/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:43:25 by danjimen          #+#    #+#             */
/*   Updated: 2024/09/10 22:44:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	putstr(char	*str, int i)
{
	if (str == NULL)
		return (putstr("(null)", i));
	if (str[i] == '\0')
		return (i);
	write(1, &str[i], 1);
	return (putstr(str, i + 1));
}

int putnbr(long nbr, int base)
{
	char	*b = "0123456789abcdef";
	if (nbr < 0)
		return (write(1, "-", 1) + putnbr(nbr * -1, base));
	if (nbr / base == 0)
		return (write(1, &b[nbr % base], 1));
	return (putnbr(nbr / base, base) + putnbr(nbr % base, base));
}

int	ptf(char *s, va_list args, int i, int n)
{
	if (s[i] == '\0')
		return n;
	if (s[i] == '%' && s[i + 1] == 's')
		return (ptf(s,args, i + 2, n + putstr(va_arg(args, char *), 0)));
	if (s[i] == '%' && s[i + 1] == 'd')
		return (ptf(s, args, i + 2, n + putnbr(va_arg(args, int), 10)));
	if (s[i] == '%' && s[i + 1] == 'x')
		return (ptf(s, args, i + 2, n + putnbr(va_arg(args, int), 16)));
	write(1, &s[i], 1);
	return (ptf(s, args, i + 1, n + 1));
}

int ft_printf(char *s, ... )
{
	va_list args;
	return (va_start(args, s), va_end(args), ptf(s, args, 0, 0));
}

//#include <stdio.h>

int	main(void)
{
	char	*str = "Hola!";
	int		count;

	count = ft_printf("%s\n", str);
	ft_printf("He impreso %d caracteres.\n", count);
	count = ft_printf("255 en hexa: %x\n", 255);
	ft_printf("He impreso %d caracteres.\n", count);
	return (count);
}


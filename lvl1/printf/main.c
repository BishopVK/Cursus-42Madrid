/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:07:50 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/06 17:07:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//cc main.c libftprintf.a && ./a.out > salida.txt 2> error.txt
int	main(void)
{
	int				i = -123;
	unsigned int	ui = 42;
	char			c = 'D';
	char			*str = "Hola mundo";
	int				x = 25;
	int				X = 1024;

	ft_printf("\n--FT_PRINTF--\n");
	ft_printf("%%\n");
	ft_printf("int = %d\n", i);
	ft_printf("unsigned int = %u\n", ui);
	ft_printf("char = %c\n", c);
	ft_printf("char* = %s\n", str);
	ft_printf("%d in hex = %x\n", x, x);
	ft_printf("%d in HEX = %X\n", X, X);
	ft_printf("Pointer = %p\n", i);

	ft_dprintf(1, "\n--FT_DPRINTF STDOUT--\n");
	ft_dprintf(1, "%%\n");
	ft_dprintf(1, "int = %d\n", i);
	ft_dprintf(1, "unsigned int = %u\n", ui);
	ft_dprintf(1, "char = %c\n", c);
	ft_dprintf(1, "char* = %s\n", str);
	ft_dprintf(1, "%d in hex = %x\n", x, x);
	ft_dprintf(1, "%d in HEX = %X\n", X, X);
	ft_dprintf(1, "Pointer = %p\n", i);

	ft_dprintf(2, "\n--FT_DPRINTF STDERROR--\n");
	ft_dprintf(2, "%%\n");
	ft_dprintf(2, "int = %d\n", i);
	ft_dprintf(2, "unsigned int = %u\n", ui);
	ft_dprintf(2, "char = %c\n", c);
	ft_dprintf(2, "char* = %s\n", str);
	ft_dprintf(2, "%d in hex = %x\n", x, x);
	ft_dprintf(2, "%d in HEX = %X\n", X, X);
	ft_dprintf(2, "Pointer = %p\n", i);

	return(0);
}

//cc -Wall -Wextra -Werror main.c libftprintf.a && ./a.out
// Comparison between the operation of printf() and my ft_printf()
/* int	main(void)
{
	int	size;

	char	c = 'D';
	printf("\nCHAR (c):\n");
	size = printf("Printf: %c\n", c);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %c\n", c);
	printf("Size ft_printf: %d\n", size); 

	int		n = -123;
	printf("\nINTEGER (i):\n");
	size = printf("Printf: %i\n", n);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %i\n", n);
	printf("Size ft_printf: %d\n", size);

	printf("\nINTEGER (d):\n");
	size = printf("Printf: %d\n", n);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %d\n", n);
	printf("Size ft_printf: %d\n", size);

	unsigned int	ui = 42;
	printf("\nUNSIGNED INTEGER (u):\n");
	size = printf("Printf: %u\n", ui);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %u\n", ui);
	printf("Size ft_printf: %d\n", size);

	printf("\nPERCENTAGE (%%):\n");
	size = printf("Printf: %%\n");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %%\n");
	printf("Size ft_printf: %d\n", size);

	char	*s = "Hello World!";
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
	printf("\nPOINTER (p):\n");
	size = printf("Printf: %p\n", (void *)p);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %p\n", (void *)p);
	printf("Size ft_printf: %d\n", size);

	printf("\nVOID POINTER(p):\n");
	size = printf("Printf: %p\n", "");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %p\n", "");
	printf("Size ft_printf: %d\n", size);

	unsigned int	x = -1;
	printf("\nLOWERCASE HEXADECIMAL (x):\n");
	size = printf("Printf: %x\n", x);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %x\n", x);
	printf("Size ft_printf: %d\n", size);

	unsigned int	xx = -1;
	printf("\nUPPERCASE HEXADECIMAL(X):\n");
	size = printf("Printf: %X\n", xx);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %X\n", xx);
	printf("Size ft_printf: %d\n", size);

	printf("\nVOID PRINT:\n");
	//size = printf("");
	//printf("Size Printf: %d\n", size);
	size = ft_printf("");
	printf("Size ft_printf: %d\n", size);

	printf("\nWRONG CONVERSION:\n");
	//size = printf("Printf: %r\n", n);
	//printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %r\n", n);
	printf("Size ft_printf: %d\n", size);

	printf("\nNOT PRINTABLE:\n");
	size = printf("Printf: \001\002\007\v\010\f\r\n");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: \001\002\007\v\010\f\r\n");
	printf("Size ft_printf: %d\n", size);

	printf("\nMULTIPLE CONVERSIONS:\n");
	size = printf("Printf: int = %i, char = %c, str = %s, hex = %x\n",
		n, c, s, x);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: int = %i, char = %c, str = %s, hex = %x\n",
		n, c, s, x);
	printf("Size ft_printf: %d\n", size);

	return (0);
} */
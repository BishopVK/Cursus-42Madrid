/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:39:28 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/30 14:16:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	mask;

	i = 0;
	mask = 128;
	while (i < 8)
	{
		if (octet & mask)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask >>= 1;
		i++;
	}
}

/* unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	swap;

	swap = octet << 4;
	octet >>= 4;
	octet |= swap;
	return (octet);
} */

unsigned char	reverse_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main(void)
{
	unsigned char	octet;

	octet = 65;
	print_bits(octet);
	write(1, "\n", 1);
	octet = reverse_bits(octet);
	print_bits(octet);
	write(1, "\n", 1);
	return (0);
}
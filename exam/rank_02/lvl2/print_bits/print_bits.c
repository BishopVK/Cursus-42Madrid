/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:07:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/30 08:31:40 by danjimen         ###   ########.fr       */
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

int	main(void)
{
	unsigned char	octet;

	octet = 2;
	print_bits(octet);
	return (0);
}
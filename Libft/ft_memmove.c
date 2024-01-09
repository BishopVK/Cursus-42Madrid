/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:18:18 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/09 13:55:43 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <strings.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (dest_tmp < src_tmp || dest_tmp >= (src_tmp + n))
	{
		while (n--)
			*dest_tmp++ = *src_tmp++;
	}
	else
	{
		dest_tmp += n - 1;
		src_tmp += n - 1;
		while (n--)
			*dest_tmp-- = *src_tmp--;
	}
	return (dest);
}

/*int	main(void)
{
	char	dest[50];
	char	src[] = "En un lugar de la mancha";

	printf("src: %s\n", src);
	ft_memmove(dest, src, 22);
	printf("dest después de la copia: %s\n", dest);
	return (0);
}*/

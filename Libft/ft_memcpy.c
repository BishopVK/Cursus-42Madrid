/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:33 by danjimen          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/10 10:58:07 by danjimen         ###   ########.fr       */
=======
/*   Updated: 2024/01/09 13:55:20 by danjimen         ###   ########.fr       */
>>>>>>> 5cdaccca6c086fd312689e53030e93ed900cc2bd
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <strings.h>

<<<<<<< HEAD
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char *)dst;
=======
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
>>>>>>> 5cdaccca6c086fd312689e53030e93ed900cc2bd
	src_tmp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
<<<<<<< HEAD
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
=======
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
>>>>>>> 5cdaccca6c086fd312689e53030e93ed900cc2bd
}

/*int	main(void)
{
<<<<<<< HEAD
	char	dst[50];
	char	src[] = "En un lugar de la mancha";

	printf("src: %s\n", src);
	ft_memcpy(dst, src, 25);
	printf("dest después de la copia: %s\n", dst);
=======
	char	dest[50];
	char	src[] = "En un lugar de la mancha";

	printf("src: %s\n", src);
	ft_memcpy(dest, src, 25);
	printf("dest después de la copia: %s\n", dest);
>>>>>>> 5cdaccca6c086fd312689e53030e93ed900cc2bd
	return (0);
}*/

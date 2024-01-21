/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: danjimen <danjimen@student.42madrid>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/10 08:31:47 by danjimen		  #+#	#+#			 */
/*   Updated: 2024/01/16 08:57:08 by danjimen		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dst_lenght;
	size_t	i;

	src_length = ft_strlen(src);
	dst_lenght = ft_strlen(dst);
	if (dstsize <= dst_lenght)
		return (src_length + dstsize);
	i = 0;
	while (src[i] != '\0' && i < dstsize - dst_lenght - 1)
	{
		dst[dst_lenght + i] = src[i];
		i++;
	}
	dst[dst_lenght + i] = '\0';
	return (src_length + dst_lenght);
}

/*int	main(void)
{
	char			dst[30] = "Hola ";
	char			src[] = "mundo1234567890abcdefghi";
	unsigned int	length;

	length = ft_strlcat(dst, src, 20);
	printf("%s\n", dst);
	printf("%u\n", length);
	return (0);
}*/

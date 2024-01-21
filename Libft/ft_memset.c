/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memset.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: danjimen <danjimen@student.42madrid>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/09 07:50:57 by danjimen		  #+#	#+#			 */
/*   Updated: 2024/01/12 12:23:17 by danjimen		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = b;
	i = 0;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (b);
}

/*int	main(void)
{
	char str[] = "Replicando la función memset";

	printf("Inicial: %s\n", str);
	ft_memset(str, '$', 4);
	printf("Después: %s\n", str);
	return (0);
}*/

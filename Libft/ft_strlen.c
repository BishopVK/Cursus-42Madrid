/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlen.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: danjimen <danjimen@student.42madrid.com>   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/08 19:03:22 by danjimen		  #+#	#+#			 */
/*   Updated: 2024/01/12 10:10:36 by danjimen		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

/*int	main(void)
{
	char	str[] = "HOLA Caracola";
	int		lenght;
	
	lenght = ft_strlen(str);
	printf("String: %s\n", str);
	printf("Longitud: %d\n", lenght);

	return (0);
}*/

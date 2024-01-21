/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isalnum.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: danjimen <danjimen@student.42madrid.com>   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/08 19:28:22 by danjimen		  #+#	#+#			 */
/*   Updated: 2024/01/13 23:38:23 by danjimen		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	char	c;

	c = '5';
	printf("%d\n", ft_isalnum(c));
	return (0);
}*/

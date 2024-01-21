/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_tolower.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: danjimen <danjimen@student.42madrid>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/10 11:15:33 by danjimen		  #+#	#+#			 */
/*   Updated: 2024/01/10 11:22:19 by danjimen		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*int	main(void)
{
	printf("Letra recibida: %c\n", ft_tolower('Z'));
	return (0);
}*/

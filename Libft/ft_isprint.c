/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:41:13 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/08 19:01:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*int	main(void)
{
	char	c;
	int		num;

	c = 31;
	num = ft_isprint(c);
	if (num == 1)
		printf("El caracter introducido SI es imprimible\n");
	else
		printf("El caracter introducido NO es imprimible\n");
	return (0);
}*/
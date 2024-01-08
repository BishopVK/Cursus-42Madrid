/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:03:22 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/08 19:13:47 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

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

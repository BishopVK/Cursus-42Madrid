/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:51:57 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/29 17:51:57 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	my_function(int *i)
{
	printf("i1 = %d\n", *i);
	(*i)++;
	printf("i2 = %d\n", *i);
	(*i)++;
	printf("i3 = %d\n", *i);
	(*i)++;
	printf("i4 = %d\n", *i);
	(*i)++;
	printf("i5 = %d\n", *i);
	(*i)++;
}

int	main(void)
{
	int	i;
	
	i = 1;
	my_function(&i);
	printf("Final = %d\n", i);
	return (0);
}

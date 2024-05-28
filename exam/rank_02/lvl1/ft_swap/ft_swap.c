/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:03:38 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 11:08:18 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/* #include <stdio.h>

int	main(void)
{
	int	a = 42;
	int	b = 9;
	printf("--BEFORE:--\n");
	printf("a = %i\n", a);
	printf("b = %i\n", b);
	ft_swap(&a, &b);
	printf("--AFTER:--\n");
	printf("a = %i\n", a);
	printf("b = %i\n", b);
	return (0);
} */
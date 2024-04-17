/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_norminette.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:12 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/16 12:46:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**************************************************************/
/*  3 EJEMPLOS CADA VEZ MÁS SIMPLIFICADOS QUE HACEN LO MISMO  */
/**************************************************************/

// 1. Clásico (12 líneas)
int	main(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i % 2 == 0)
			printf("%d es par\n", i);
		else
			printf("%d es impar\n", i);
		i++;
	}
	return (0);
}

// 2. Sintetizado (10 líneas)
/* int	main(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		(i % 2 == 0) && printf("%d es par\n", i);
		(i % 2 != 0) && printf("%d es impar\n", i);
		i++;
	}
	return (0);
} */

// 3. Minimal (6 líneas)
/* int	main(void)
{
	int	i;

	i = -1;
	while (++i < 10)
		(i % 2 != 0 && printf("%d es impar\n", i)) || (i % 2 == 0 && printf("%d es par\n", i));
	return (0);
} */

/***********************************************/
/*  VARIAS OPERACIONES EN CADA UNO DE LOS IFS  */
/***********************************************/

// 1. Clásico (18 líneas)
/* int	main(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i % 2 == 0)
		{
			printf("%d es par\n", i);
			printf("%d^2 = %i\n", i, (i * i));
		}
		else
		{
			printf("%d es impar\n", i);
			printf("%d^2 = %i\n", i, (i * i));
		}
		i++;
	}
	return (0);
} */

// 2. Sintetizado (10 líneas)
/* int	main(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		(i % 2 == 0) && (printf("%d es par\n", i), printf("%d^2 = %i\n", i, (i * i)));
		(i % 2 != 0) && (printf("%d es impar\n", i), printf("%d^2 = %i\n", i, (i * i)));
		i++;
	}
	return (0);
} */

// 3. Minimal (7 líneas)
/* int	main(void)
{
	int	i;

	i = -1;
	while (++i < 10)
		(i % 2 != 0) && (printf("%d es impar\n", i),
				printf("%d^2 = %i\n", i, (i * i))
			|| ((i % 2 == 0) && printf("%d es par\n", i)),
				printf("%d^2 = %i\n", i, (i * i)));
	return (0);
} */

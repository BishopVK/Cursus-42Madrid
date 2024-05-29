/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:34:54 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 10:59:57 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char **argv)
{
	int		nbr1;
	char	*operator;
	int		nbr2;

	if (argc == 4)
	{
		nbr1 = atoi(argv[1]);
		operator = argv[2];
		nbr2 = atoi(argv[3]);
		if (operator[0] == '+')
			printf("%i", nbr1 + nbr2);
		else if (operator[0] == '-')
			printf("%i", nbr1 - nbr2);
		else if (operator[0] == '*')
			printf("%i", nbr1 * nbr2);
		else if (operator[0] == '/')
			printf("%i", nbr1 / nbr2);
		else if (operator[0] == '%')
			printf("%i", nbr1 % nbr2);
	}
	printf("\n");
	return (0);
}

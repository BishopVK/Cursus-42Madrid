/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/25 08:08:11 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(int argc, char const *argv[])
{
	if (strcmp(argv[1], "HOLA") == 0)
		printf("Hola a ti también\n");
	else
		printf("Pues adios!!\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:32:06 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/23 21:38:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// Prototipo:	int usleep(useconds_t usec);
// Descripción:	Suspende la ejecución del programa durante al menos usec microsegundos.

int	main(void)
{
	printf("1\n");
	// 1000000 de microsegundos == 1 segundo
	usleep(1000000);
	printf("2\n");
	usleep(1000000);
	printf("3\n");
	usleep(1000000);
	printf("4\n");
	usleep(1000000);
	printf("5\n");
	return (0);
}

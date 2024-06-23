/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:36:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/23 21:44:29 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

// Prototipo:	int gettimeofday(struct timeval *tv, struct timezone *tz);
// Descripción:	Obtiene la hora actual y la almacena en la estructura tv. 
// 				La estructura tz se utiliza para almacenar la zona horaria, pero generalmente se pasa NULL.

// struct timeval
// {
// 	time_t		tv_sec;		/* seconds */
// 	suseconds_t	tv_usec;	/* microseconds */
// };

// struct timezone
// {
// 	int	tz_minuteswest;	/* minutes west of Greenwich */
// 	int	tz_dsttime;		/* type of DST correction */
// };

int	main(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	printf("time seconds= %li\n", tv.tv_sec);
	printf("time microseconds= %li\n", tv.tv_usec);
	return (0);
}

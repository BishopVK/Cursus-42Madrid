/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:11:02 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/10 13:11:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2 || argc > 5)
		return (-1);
	else
	{
		while (argv[i])
		{
			printf("argv[%d] = %s\n", i, argv[i]);
			i++;
		}
	}
	return (0);
}

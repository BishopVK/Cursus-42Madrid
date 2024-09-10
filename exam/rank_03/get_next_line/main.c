/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:13:31 by danjimen          #+#    #+#             */
/*   Updated: 2024/09/10 20:17:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("txt.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 1;
	while (line != NULL)
	{
		printf("line %i: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++; 
	}
	free(line);
	close(fd);
	return (0);
}
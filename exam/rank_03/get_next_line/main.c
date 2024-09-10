/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.e      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:08:25 by danjimen          #+#    #+#             */
/*   Updated: 2024/09/10 14:35:16 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int	fd;
	int	i;


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

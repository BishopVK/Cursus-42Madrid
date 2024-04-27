/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:57:34 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/24 12:57:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	here_doc(char *limit)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	int		fd;
	char	*eof;

	eof = (char *)ft_calloc((ft_strlen(limit) + 2), sizeof(char));
	if (eof == NULL)
		exit (1);
	ft_strcpy(eof, limit);
	eof[ft_strlen(limit)] = '\n';
	fd = open_fd("tmp/tmp.txt", 11);
	while (1)
	{
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
		
		if (bytes_read == -1) {
			perror("Error al leer de stdin");
			return (1);
		}
		if (bytes_read == 0)
			break ;
		if (ft_memcmp(buffer, eof, bytes_read) == 0)
		{
			// Se encontró EOF, termina el bucle
			free(eof);
			break ;
		}
		if (write(fd, buffer, bytes_read) != bytes_read)
		{
			perror("Error al escribir en el fd");
			return (1);
		}
	}
	return (fd);
}

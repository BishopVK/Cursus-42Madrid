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

static void	create_fd(char *eof, int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	while (1)
	{
		ft_printf("> ");
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			perror("Error reading from stdin");
			exit (1);
		}
		if (bytes_read == 0)
			break ;
		if (ft_memcmp(buffer, eof, bytes_read) == 0)
		{
			free(eof);
			break ;
		}
		if (write(fd, buffer, bytes_read) != bytes_read)
		{
			perror("Error writing to fd");
			exit (1);
		}
	}
}

void	here_doc(char **argv)
{
	int		fd;
	char	*eof;
	char	*limit;

	limit = argv[2];
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		eof = (char *)ft_calloc((ft_strlen(limit) + 2), sizeof(char));
		if (eof == NULL)
			exit (1);
		ft_strcpy(eof, limit);
		eof[ft_strlen(limit)] = '\n';
		fd = open_fd("tmp.txt", 1);
		create_fd(eof, fd);
		close(fd);
	}
}

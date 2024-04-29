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

/* void	here_doc_child1(char **argv, int *p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	fd = open_fd("tmp/tmp.txt", 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	unlink("tmp/tmp.txt");
	close(p_fd[0]);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	if (ft_strncmp(argv[3], "awk", 3) == 0)
		split_argv = ft_split_awk(argv[3], ' ');
	else
		split_argv = ft_split(argv[3], ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
	free_split(split_argv);
} */

/* void	here_doc_child2(char **argv, int *p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	fd = open_fd(argv[5], 11);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	if (ft_strncmp(argv[4], "awk", 3) == 0)
		split_argv = ft_split_awk(argv[4], ' ');
	else
		split_argv = ft_split(argv[4], ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
	free_split(split_argv);
} */

static void	create_fd(char *eof, int fd)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
		
		if (bytes_read == -1) {
			perror("Error al leer de stdin");
			exit (1);
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
		fd = open_fd("tmp/tmp.txt", 1);
		//ft_printf("DETECTADO\n");
		create_fd(eof, fd);
		//system("cat tmp/tmp.txt");
		//ft_printf("Cerramos el fd\n");
		close(fd);
		//ft_printf("Eliminamos el fd\n");
		//unlink("tmp/tmp.txt");
	}
}

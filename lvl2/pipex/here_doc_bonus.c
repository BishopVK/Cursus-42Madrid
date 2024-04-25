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

void	here_doc_read_buffer(int fd, char *eof)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];
	char	*eof_pos;

	bytes_read = 0;
	while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd, buffer, bytes_read) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		// Buscar el límite del here_doc
		eof_pos = ft_strstr(buffer, eof);
		if (eof_pos != NULL)
			break;
	}
	if (bytes_read == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
}

void	here_doc_child1(int *p_fd, char **env, char *cmd1)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	//int		fd;

	// Cerrar el extremo de lectura del pipe en el proceso hijo
	close(p_fd[READ_END]);

	// Redirigir la salida estándar al extremo de escritura del pipe
	dup2(p_fd[WRITE_END], STDOUT_FILENO);

	// Cerrar el extremo de escritura del pipe en el proceso hijo
	close(p_fd[WRITE_END]);

	// Ejecutar el primer comando
	split_argv = ft_split(cmd1, ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
	free_split(split_argv);
}

void	here_doc_child2(char **argv, int *p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	fd = open_fd(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	split_argv = ft_split(argv[3], ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
	free_split(split_argv);
}

void	here_doc_second_fork(char **argv, char **env, int *p_fd, pid_t pid1)
{
	pid_t	pid2;
	int		status;

	pid2 = fork();
	if (pid2 == -1)
		exit(-1);
	if (pid2 == 0)
		here_doc_child2(argv, p_fd, env);
	else if (pid2 > 0)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
	}
}

void	here_doc(char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid1;
	char	*cmd1;
	char	*eof;

	cmd1 = argv[3];
	eof = argv[2];
	if (pipe(p_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 == -1)
		exit(-1);
	if (pid1 == 0)
		here_doc_child1(p_fd, env, cmd1);
	else if (pid1 > 0)
	{
		here_doc_read_buffer(p_fd[0], eof);
		here_doc_second_fork(argv, env, p_fd, pid1);
	}
}
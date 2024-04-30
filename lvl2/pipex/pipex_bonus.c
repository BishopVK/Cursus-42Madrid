/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/22 14:08:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fitst_child(char **argv, int *p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		fd = open_fd("tmp/tmp.txt", 0);
		split_argv = ft_split_awk(argv[3], ' ');
	}
	else
	{
		fd = open_fd(argv[1], 0);
		split_argv = ft_split_awk(argv[2], ' ');
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	unlink("tmp/tmp.txt");
	close(p_fd[0]);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
}

void	middle_child(char **argv, int *p_fd, int *next_p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	close(p_fd[1]);
	fd = p_fd[0];
	dup2(fd, STDIN_FILENO);
	close(fd);
	close(next_p_fd[0]);
	fd = next_p_fd[1];
	dup2(fd, STDOUT_FILENO);
	close(fd);
	split_argv = ft_split_awk(argv[2], ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
}

void	last_child(char **argv, int *p_fd, char **env, int argc)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	//ft_printf("argc - 1 = %d\n", argc - 1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		fd = open_fd(argv[argc - 1], 11);
	else
		fd = open_fd(argv[argc - 1], 1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	//ft_printf("argc - 2 = %d\n", argc - 2);
	split_argv = ft_split_awk(argv[argc - 2], ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
}

/* int	second_fork(char **argv, char **env, int *p_fd, int argc)
{
	pid_t	pid2;
	int		status;

	status = 0;
	pid2 = fork();
	if (pid2 == -1)
		exit(-1);
	if (pid2 == 0)
		last_child(argv, p_fd, env, argc);
	else if (pid2 > 0)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		wait(&status);
		status = WEXITSTATUS(status);
	}
	return (status);
} */

int	second_fork(char **argv, char **env, int *p_fd, int argc)
{
	pid_t	pid;
	int		status;
	int		num_pipes;
	int		i;
	int		next_p_fd[2];

	if (ft_strcmp(argv[1], "here_doc") == 0)
		num_pipes = argc - 5;
	else
		num_pipes = argc - 4;

	i = 0;
	while (i < num_pipes)
	{
		if (pipe(p_fd) == -1)
			exit (-1);
		pid = fork();
		if (pid == -1)
			exit (-1);
		if (pid == 0)
		{
			if (i = 0)
				fitst_child(argv, p_fd, env);
			else if (i == num_pipes - 1)
				last_child(argv, p_fd, env, argc);
			else
				middle_child(argv, p_fd, next_p_fd, env, i);
			exit (0);
		}
		else
		{
			if (i > 0)
			{
				close(next_p_fd[0]); // Cierra el extremo de lectura del pipe siguiente
				close(next_p_fd[1]); // Cierra el extremo de escritura del pipe siguiente del proceso padre anterior
			}
			next_p_fd[0] = p_fd[0]; // Almacena el descriptor de archivo del extremo de lectura del pipe actual
			next_p_fd[1] = p_fd[1]; // Almacena el descriptor de archivo del extremo de escritura del pipe actual
		}
		i++;
	}
	// Proceso padre
	i = 0;
	while (i < num_pipes)
		close(p_fd[i++]);

	i = -1;
	while (++i < num_pipes)
		wait(&status);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	//pid_t	pid1;

	if (argc < 5)
	{
		ft_dprintf(2, "Correct use: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"
			"Or: ./pipex here_doc LIMITADOR \"cmd\" \"cmd1\" outfile\n");
		return (-1);
	}
	here_doc(argv);
	return (second_fork(argv, env, p_fd, argc));
	/* if (pipe(p_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 == -1)
		exit(-1);
	if (pid1 == 0)
		fitst_child(argv, p_fd, env);
	else if (pid1 > 0)
		return (second_fork(argv, env, p_fd, argc)); */
	return (0);
}

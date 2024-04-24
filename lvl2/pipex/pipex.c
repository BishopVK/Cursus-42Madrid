/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:54 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/22 14:08:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char **split_argv, char *full_path, char **env)
{
	if (full_path != NULL && access(full_path, X_OK) == 0)
	{
		execve(full_path, split_argv, env);
		perror("execve failed");
		exit (127);
	}
	else
	{
		if (full_path == NULL)
		{
			ft_dprintf(2, "The full path of the command was not found\n");
			exit (127);
		}
		else
		{
			ft_dprintf(2, "The command is not accessible\n");
			exit (127);
		}
	}
}

void	child1(char **argv, int *p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	fd = open_fd(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	close(p_fd[0]);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	ft_printf("El primer comando es: %s\n",	argv[2]);
	/* if (ft_strncmp(argv[2], "awk", 3) == 0)
	{
		ft_printf("He detectado AWK en el 1º comando\n");
		split_argv = awk_split(argv[2]);
	}
	else
		split_argv = ft_split(argv[2], ' '); */
	split_argv = ft_split(argv[2], ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
	free_split(split_argv);
}

void	child2(char **argv, int *p_fd, char **env)
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
	ft_printf("El segundo comando es: %s\n",	argv[3]);
	/* if (ft_strncmp(argv[3], "awk", 3) == 0)
	{
		ft_printf("He detectado AWK en el 2º comando\n");
		split_argv = awk_split(argv[3]);
	}
	else
		split_argv = ft_split(argv[3], ' '); */
	split_argv = ft_split(argv[3], ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
	free_split(split_argv);
}

void	second_fork(char **argv, char **env, int *p_fd, pid_t pid1)
{
	pid_t	pid2;
	int		status;

	pid2 = fork();
	if (pid2 == -1)
		exit(-1);
	if (pid2 == 0)
		child2(argv, p_fd, env);
	else if (pid2 > 0)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid1;

	if (argc != 5)
	{
		ft_dprintf(2, "Correct use: %s infile \"cmd1\" \"cmd2\" outfile\n",
			argv[0]);
		return (-1);
	}
	if (pipe(p_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 == -1)
		exit(-1);
	if (pid1 == 0)
		child1(argv, p_fd, env);
	else if (pid1 > 0)
		second_fork(argv, env, p_fd, pid1);
	return (0);
}

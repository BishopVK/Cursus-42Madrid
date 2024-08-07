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
	if (ft_strncmp(argv[2], "awk", 3) == 0)
		split_argv = ft_split_awk(argv[2], ' ');
	else
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
	if (ft_strncmp(argv[3], "awk", 3) == 0)
		split_argv = ft_split_awk(argv[3], ' ');
	else
		split_argv = ft_split(argv[3], ' ');
	split_path = get_path(env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, env);
	free_split(split_argv);
}

int	second_fork(char **argv, char **env, int *p_fd, pid_t pid1)
{
	pid_t	pid2;
	int		status;

	status = 0;
	pid2 = fork();
	if (pid2 == -1)
		exit(-1);
	if (pid2 == 0)
	if (ft_strcmp(argv[1], "here_doc") == 0)
		here_doc_child2(argv, p_fd, env);
	else
		child2(argv, p_fd, env);
	else if (pid2 > 0)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
		status = WEXITSTATUS(status);
	}
	return (status);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid1;

	if (argc < 5)
	{
		ft_dprintf(2, "Correct use: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"
			"Or: ./pipex here_doc LIMITADOR \"cmd\" \"cmd1\" outfile\n");
		return (-1);
	}
	here_doc(argv);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 == -1)
		exit(-1);
	if (pid1 == 0)
	if (ft_strcmp(argv[1], "here_doc") == 0)
		here_doc_child1(argv, p_fd, env);
	else
		child1(argv, p_fd, env);
	else if (pid1 > 0)
		return (second_fork(argv, env, p_fd, pid1));
	return (0);
}

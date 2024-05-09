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

void	first_child(t_child_args *args, int *p_fd)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	if (ft_strcmp(args->argv[1], "here_doc") == 0)
	{
		fd = open_fd("tmp/tmp.txt", 0);
		split_argv = ft_split_awk(args->argv[3], ' ');
	}
	else
	{
		fd = open_fd(args->argv[1], 0);
		split_argv = ft_split_awk(args->argv[2], ' ');
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	unlink("tmp/tmp.txt");
	close(p_fd[0]);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	split_path = get_path(args->env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, args->env);
}

void	mid_child(t_child_args *args, int *p_fd, int *next_p_fd, int cmd_idx)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;

	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	close(next_p_fd[0]);
	dup2(next_p_fd[1], STDOUT_FILENO);
	close(next_p_fd[1]);
	if (ft_strcmp(args->argv[1], "here_doc") == 0)
		split_argv = ft_split_awk(args->argv[3 + cmd_idx], ' ');
	else
		split_argv = ft_split_awk(args->argv[2 + cmd_idx], ' ');
	split_path = get_path(args->env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, args->env);
}

void	last_child(t_child_args *args, int *p_fd)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	if (ft_strcmp(args->argv[1], "here_doc") == 0)
		fd = open_fd(args->argv[args->argc - 1], 11);
	else
		fd = open_fd(args->argv[args->argc - 1], 1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	split_argv = ft_split_awk(args->argv[args->argc - 2], ' ');
	split_path = get_path(args->env);
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	execute(split_argv, full_path, args->env);
}

void	childs_and_parent(t_child_args *args, pid_t pid, int **pipefd,
			int num_cmds)
{
	if (pid == -1)
		exit (1);
	if (pid == 0)
	{
		if (args->i == 0)
			first_child(args, pipefd[args->i]);
		else if (args->i == num_cmds - 1)
			last_child(args, pipefd[args->i - 1]);
		else
			mid_child(args, pipefd[args->i - 1], pipefd[args->i], args->i);
		exit (1);
	}
	if (args->i != 0)
	{
		close(pipefd[args->i - 1][0]);
		close(pipefd[args->i - 1][1]);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_child_args	args;
	int				num_cmds;
	int				**pipefd;
	pid_t			pid;

	num_cmds = define_and_validate_args(argc, argv, env, &args);
	pipefd = alloc_pipefd(num_cmds);
	while (args.i < num_cmds)
	{
		if (args.i != num_cmds - 1 && pipe(pipefd[args.i]) == -1)
			return (1);
		pid = fork();
		childs_and_parent(&args, pid, pipefd, num_cmds);
		args.i++;
	}
	args.i = 0;
	while (args.i++ < num_cmds)
		wait(NULL);
	free_pipefd(pipefd, num_cmds);
	return (0);
}

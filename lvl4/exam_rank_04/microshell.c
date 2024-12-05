/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:21:01 by danjimen          #+#    #+#             */
/*   Updated: 2024/12/05 12:28:03 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	cd(char **argv, int argc)
{
	if (argc != 2)
		return (error("error: cd: bad arguments\n"), 1);
	if (chdir(argv[1]) == -1)
		return (error("error: cd: cannot change directory to "), error(argv[1]), error("\n"), 1);
	return (0);
}

void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		error("error: fatal\n"), exit(1);
}

int	exec(char **argv, int i, char **env)
{
	int has_pipe, fd[2], pid, status;

	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (!has_pipe && !strcmp(*argv, "cd"))
		return (cd(argv, i));

	if (has_pipe && pipe(fd) == -1)
		error("error: fatal\n"), exit(1);

	if ((pid = fork()) == -1)
		error("error: fatal\n"), exit(1);

	if (!pid)
	{
		argv[i] = 0;
		set_pipe(has_pipe, fd, 1);
		if (!strcmp(*argv, "cd"))
			exit(cd(argv, i));
		execve(*argv, argv, env);
		error("error: cannot execute "), error(*argv), error("\n"), exit (1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **env)
{
	int	i = 0, status = 0;
	(void)argc;

	while (argv[i])
	{
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = exec(argv, i, env);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:08:57 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/08 19:42:06 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	define_and_validate_args(int argc, char **argv, char **env, t_child_args *args)
{
	int	num_cmds;

	args->argv = argv;
	args->env = env;
	args->i = 0;
	if (argc < 5)
	{
		ft_dprintf(2, "Correct use: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"
			"Or: ./pipex here_doc LIMITADOR \"cmd\" \"cmd1\" outfile\n");
		exit (-1);
	}
	here_doc(argv);
	if (ft_strcmp(args->argv[1], "here_doc") == 0)
		num_cmds = argc - 4;
	else
		num_cmds = argc - 3;
	return (num_cmds);
}

void	free_pipefd(char **pipefd, int num_cmds)
{
	int	i;

	i = 0;
	while (i < num_cmds - 1)
		free(pipefd[i++]);
	free(pipefd);
}

int	**alloc_pipefd(int num_cmds)
{
	int	**pipefd;
	int	i;

	pipefd = malloc((num_cmds - 1) * sizeof(int *));
	if (pipefd == NULL)
		return (NULL);
	i = 0;
	while (i < num_cmds - 1)
	{
		pipefd[i] = malloc(2 * sizeof(int));
		if (pipefd[i++] == NULL)
			return (NULL);
	}
	return (pipefd);
}

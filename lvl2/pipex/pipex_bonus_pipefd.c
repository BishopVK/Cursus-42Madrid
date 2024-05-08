/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_pipefd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:22:28 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/08 11:36:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

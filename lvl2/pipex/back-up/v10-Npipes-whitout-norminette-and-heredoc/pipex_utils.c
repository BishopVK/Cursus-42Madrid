/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:50:59 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/06 09:18:18 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

char	*find_command_in_path(const char *command, char **path_list)
{
	int		i;
	char	*full_path;

	i = 0;
	full_path = NULL;
	if (path_list == NULL && access(command, 0) == 0)
		return (ft_strdup(command));
	else if (path_list[i] != NULL)
	{
		while (path_list[i] != NULL)
		{
			full_path = malloc(ft_strlen(path_list[i])
					+ ft_strlen(command) + 2);
			if (full_path == NULL)
				exit(1);
			ft_strcpy(full_path, path_list[i]);
			full_path[ft_strlen(path_list[i])] = '/';
			ft_strcpy(full_path + ft_strlen(path_list[i]) + 1, command);
			if (access(full_path, X_OK) == 0)
				return (full_path);
			free(full_path);
			i++;
		}
	}
	return (ft_strdup(command));
}

char	**get_path(char **env)
{
	int		i;
	char	*path;
	char	**split_path;

	i = 0;
	if (env == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break ;
		}
		i++;
	}
	split_path = ft_split(path, ':');
	return (split_path);
}

int	open_fd(char *file_name, int stdin_stdout)
{
	int	fd;

	if (stdin_stdout == 0)
		fd = open(file_name, O_RDONLY, 0777);
	if (stdin_stdout == 1)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	{
		perror("open");
		exit (1);
	}
	return (fd);
}

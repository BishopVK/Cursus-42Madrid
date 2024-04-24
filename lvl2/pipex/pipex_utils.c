/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:50:59 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/24 20:07:14 by danjimen         ###   ########.fr       */
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

/* char	**awk_split(char *command)
{
	char	**split_argv;

	split_argv = (char **)malloc(3 * sizeof(char *));
	if (!split_argv)
		return (NULL);
	split_argv[0] = (char*)malloc(4 * sizeof(char));
	split_argv[1] = (char*)malloc((ft_strlen(command) - 2) * sizeof(char));
	if (split_argv[0] == NULL || split_argv[1] == NULL)
		return (NULL);
	ft_strlcpy(split_argv[0], command, 3);
	split_argv[0][3] = '\0';
	ft_printf("split_argv[0] = %s\n", split_argv[0]);
	ft_strcpy(split_argv[1], command + 4);
	ft_printf("split_argv[1] = %s\n", split_argv[1]);
	split_argv[2] = NULL;
	return (split_argv);
} */

char	*find_command_in_path(const char *command, char **path_list)
{
	int		i;
	char	*full_path;

	i = 0;
	full_path = NULL;
	while (path_list[i] != NULL)
	{
		full_path = malloc(ft_strlen(path_list[i]) + ft_strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc failed");
			exit(1);
		}
		ft_strcpy(full_path, path_list[i]);
		full_path[ft_strlen(path_list[i])] = '/';
		ft_strcpy(full_path + ft_strlen(path_list[i]) + 1, command);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	**get_path(char **env)
{
	int		i;
	char	*path;
	char	**split_path;

	i = 0;
	while (env[i] != NULL)
	{
		path = ft_strnstr(env[i], "PATH=", ft_strlen(env[i]));
		if (path != NULL)
		{
			path += 5;
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

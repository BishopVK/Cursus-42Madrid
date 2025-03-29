/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:11:52 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/29 22:49:23 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_and_update_result(char **result, char *line)
{
	char	*tmp;

	if (!result || !*result)
		return (NULL);
	ft_strlcpy(line, *result, (ft_strchr(*result, '\n') - *result) + 2);
	tmp = *result;
	*result = ft_strdup(ft_strchr(*result, '\n') + 1);
	free(tmp);
	return (line);
}

static char	*process_result(char **result)
{
	char	*line;

	if (!result || !*result)
		return (NULL);
	if (ft_strchr(*result, '\n'))
	{
		line = (char *)malloc(ft_strchr(*result, '\n') - *result + 2);
		if (line == NULL)
			return (NULL);
		line = get_line_and_update_result(result, line);
	}
	else
	{
		line = (char *)malloc(ft_strlen(*result) + 1);
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, *result, ft_strlen(*result) + 1);
		free(*result);
		*result = (NULL);
	}
	return (line);
}

int	read_file(int fd, char **result, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr(*result, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*result);
			*result = ft_strdup("");
			return (-1);
		}
		buffer[bytes_read] = '\0';
		tmp = *result;
		*result = ft_strjoin(*result, buffer);
		free(tmp);
	}
	return (bytes_read);
}

char	*get_next_line(int fd, bool free_static)
{
	char		*buffer;
	static char	*result;
	char		*line;
	int			bytes_read;

	if (free_static == true && result != NULL)
		return (free(result), NULL);
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!result)
		result = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read_file(fd, &result, buffer);
	free(buffer);
	if (bytes_read <= 0 && ft_strlen(result) == 0)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line = process_result(&result);
	return (line);
}

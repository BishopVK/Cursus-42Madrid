/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:28:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/31 08:50:17 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_7.h"

char	*ft_strdup(char *str)
{
	char	*dst;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	dst = malloc (i + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);

}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_readed;
	static int	buffer_pos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_readed <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("txt.txt", O_RDONLY);
	i = 1;
	line = get_next_line(fd);
	while(line)
	{
		printf("Line %i: %s", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
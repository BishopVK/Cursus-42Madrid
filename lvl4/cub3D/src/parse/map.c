/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:56 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/01 18:49:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	save_map(char *map, t_map_array *m_a)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(m_a, "Open error", fd);
	m_a->chars->buffer = get_next_line(fd, false);
	m_a->map = malloc((m_a->map_height + 1) * sizeof(char *));
	while (m_a->chars->buffer != NULL)
	{
		m_a->chars->buffer_trimed = ft_strtrim_isspace(m_a->chars->buffer);
		if (m_a->chars->buffer[0] != '\n'
			&& ft_strlen(m_a->chars->buffer_trimed) > 0
			&& m_a->chars->buffer_trimed[0] == '1')
		{
			printf("Se va a guardar en map_array->map[%i]: %s", i, m_a->chars->buffer); // DB
			m_a->map[i++] = ft_strdup(m_a->chars->buffer);
		}
		free(m_a->chars->buffer);
		free(m_a->chars->buffer_trimed);
		m_a->chars->buffer = get_next_line(fd, false);
	}
	m_a->map[i] = NULL;
}

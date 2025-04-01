/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:56 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/01 17:15:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	save_map(char *map, t_map_array *map_array)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_map_error(map_array, "Open error", fd);
	map_array->chars->buffer = get_next_line(fd, false);
	map_array->map = malloc((map_array->map_height + 1) * sizeof(char *));
	while (map_array->chars->buffer != NULL)
	{
		map_array->chars->buffer_trimed = ft_strtrim_isspace(map_array->chars->buffer);
		if (map_array->chars->buffer[0] != '\n'
			&& ft_strlen(map_array->chars->buffer_trimed) > 0
			&& map_array->chars->buffer_trimed[0] == '1')
		{
			printf("Se va a guardar en map_array->map[%i]: %s", i, map_array->chars->buffer); // DB
			map_array->map[i++] = ft_strdup(map_array->chars->buffer);
		}
		free(map_array->chars->buffer);
		free(map_array->chars->buffer_trimed);
		map_array->chars->buffer = get_next_line(fd, false);
	}
	map_array->map[i] = NULL;
}

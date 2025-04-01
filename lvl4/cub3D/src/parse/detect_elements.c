/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:07:07 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/01 17:45:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	keep_map_elements(char ***element, t_map_array *map_array, int fd)
{
	if (*element == NULL)
	{
		printf ("%s IS VOID\n", map_array->chars->buffer_trimed); // DB
		*element = ft_split_isspace(map_array->chars->buffer_trimed);
	}
	else
	{
		print_element(*element); // DB
		exit_map_error(map_array, "Repeated map element", fd);
	}
}

void	detect_map_elements(t_map_array *map_array, int fd)
{
	char	*trimed;

	trimed = map_array->chars->buffer_trimed;
	if (ft_strlen(map_array->chars->buffer_trimed) > 3)
	{
		if (trimed[0] == 'N' && trimed[1] == 'O' && ft_isspace(trimed[2]))
			keep_map_elements(&map_array->north, map_array, fd);
		else if (trimed[0] == 'S' && trimed[1] == 'O' && ft_isspace(trimed[2]))
			keep_map_elements(&map_array->south, map_array, fd);
		else if (trimed[0] == 'W' && trimed[1] == 'E' && ft_isspace(trimed[2]))
			keep_map_elements(&map_array->west, map_array, fd);
		else if (trimed[0] == 'E' && trimed[1] == 'A' && ft_isspace(trimed[2]))
			keep_map_elements(&map_array->east, map_array, fd);
		else if (trimed[0] == 'F' && ft_isspace(trimed[1]))
			keep_map_elements(&map_array->floor->element, map_array, fd);
		else if (trimed[0] == 'C' && ft_isspace(trimed[1]))
			keep_map_elements(&map_array->ceiling->element, map_array, fd);
		else
		{
			printf("%s", map_array->chars->buffer); // DB
			exit_map_error(map_array, "Not a valid element detected", fd);
		}
	}
	else
		exit_map_error(map_array, "Not a valid element detected", fd);
}
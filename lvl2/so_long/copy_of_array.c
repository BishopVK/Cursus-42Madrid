/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_of_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:53:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/23 12:49:10 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_array_copy(t_map_array *map_array)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	copy = (char **)malloc((map_array->height + 1) * sizeof(char *));
	while (i < map_array->height)
	{
		copy[i] = (char *)malloc(map_array->width + 1);
		if (!copy[i])
		{
			j = 0;
			while (j < i)
			{
				free(copy[j]);
				j++;
			}
			free(copy);
			return (NULL);
		}
		ft_strcpy(copy[i], map_array->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

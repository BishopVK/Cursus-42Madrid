/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_of_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:53:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/23 09:14:57 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_array_copy(char **originalMap, int width, int height)
{
	int	i;
	char **copy;

	i = 0;
	copy = (char **)malloc(height * sizeof(char *));
	while (i < height)
	{
		copy[i] = (char *)malloc(width * sizeof(char));
		ft_strcpy(copy[i], originalMap[i]);
		i++;
	}
	return (copy);
}

/* void	free_map_copy(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
} */

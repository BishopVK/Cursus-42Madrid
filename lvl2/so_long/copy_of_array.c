/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_of_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:53:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/22 23:27:30 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_array_copy(char **originalMap, int width, int height) {
	char **copy = (char **)malloc(height * sizeof(char *));
	for (int i = 0; i < height; i++) {
		copy[i] = (char *)malloc(width * sizeof(char));
		ft_strcpy(copy[i], originalMap[i]);
	}
	return copy;
}

void	freeMapCopy(char **map, int height) {
	for (int i = 0; i < height; i++) {
		free(map[i]);
	}
	free(map);
}
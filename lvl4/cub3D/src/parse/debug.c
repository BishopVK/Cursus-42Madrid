/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:01:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/01 18:23:23 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_rgb_values(t_rgb *element)
{
	printf("%s element:\n", element->element[0]);
	printf("R = %i\n", element->r);
	printf("G = %i\n", element->g);
	printf("B = %i\n", element->b);
}

void	print_element(char **element)
{
	int	i;

	i = 0;
	if (element)
	{
		while (element[i])
		{
			printf ("%s ", element[i]);
			i++;
		}
		printf("\n");
	}
}

void	print_elements(t_map_array *map_array)
{
	print_element(map_array->north);
	print_element(map_array->south);
	print_element(map_array->west);
	print_element(map_array->east);
	print_element(map_array->floor->element);
	print_element(map_array->ceiling->element);
}

void	print_map(t_map_array *map_array)
{
	int	i;

	i = 0;
	printf("\n-- MAP SAVED --\n");
	while (map_array->map[i])
	{
		printf("%s", map_array->map[i]);
		i++;
	}
	printf("\n");
}
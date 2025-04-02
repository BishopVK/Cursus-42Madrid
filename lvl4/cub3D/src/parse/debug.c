/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:01:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/02 16:01:26 by danjimen         ###   ########.fr       */
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

void	print_elements(t_map *map_s)
{
	print_element(map_s->north);
	print_element(map_s->south);
	print_element(map_s->west);
	print_element(map_s->east);
	print_element(map_s->floor->element);
	print_element(map_s->ceiling->element);
}

void	print_map(t_map *map_s)
{
	int	i;

	i = 0;
	printf("\n-- MAP SAVED --\n");
	while (map_s->map[i])
	{
		printf("%s", map_s->map[i]);
		i++;
	}
	printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:10:36 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/02 16:02:18 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_element_path(t_map *m_a,
	char **element, int count)
{
	int	i;
	int	fd;

	i = 0;
	while (element[i])
	{
		if (i == 1)
		{
			fd = open(element[i], O_RDONLY);
			if (fd == -1)
			{
				if (errno == ENOENT)
					exit_map_error(m_a, "Texture file does not exist", fd);
				else if (errno == EACCES)
					exit_map_error(m_a, "Texture file is not readable", fd);
				else
					exit_map_error(m_a, "Error opening texture file", fd);
			}
			close(fd);
		}
		count++;
		i++;
	}
	if (count != 2)
		exit_map_error(m_a, "The texture element is incorrect", -1);
}

static void	save_rgb_values(t_rgb *element, char **splited)
{
	element->r = ft_atoi(splited[0]);
	element->g = ft_atoi(splited[1]);
	element->b = ft_atoi(splited[2]);
}

static void	check_rgb_values(t_map *map_s, char **splited, int *count_colors)
{
	int	j;
	int	k;

	j = 0;
	while (splited[j])
	{
		k = 0;
		while (splited[j][k])
		{
			if (!ft_isdigit(splited[j][k]) || k > 2)
			{
				free_double_pointer(splited);
				exit_map_error(map_s, "Invalid RGB value", -1);
			}
			k++;
		}
		if (ft_atoi(splited[j]) < 0 || ft_atoi(splited[j]) > 255)
		{
			free_double_pointer(splited);
			exit_map_error(map_s, "Invalid RGB range color", -1);
		}
		(*count_colors)++;
		j++;
	}
}

static void	check_element_rgb(t_map *map_s, t_rgb *element, int i)
{
	int		count_elements;
	char	**splited;
	int		count_colors;

	count_elements = 0;
	while (element->element[i])
	{
		if (i == 1)
		{
			splited = ft_split(element->element[i], ',');
			count_colors = 0;
			check_rgb_values(map_s, splited, &count_colors);
			if (count_colors != 3)
			{
				free_double_pointer(splited);
				exit_map_error(map_s, "Invalid RGB color", -1);
			}
			save_rgb_values(element, splited);
			free_double_pointer(splited);
		}
		count_elements++;
		i++;
	}
	if (count_elements != 2)
		exit_map_error(map_s, "The RGB element is incorrect", -1);
}

void	check_elements(t_map *map_s)
{
	check_element_path(map_s, map_s->north, 0);
	check_element_path(map_s, map_s->south, 0);
	check_element_path(map_s, map_s->west, 0);
	check_element_path(map_s, map_s->east, 0);
	check_element_rgb(map_s, map_s->floor, 0);
	check_element_rgb(map_s, map_s->ceiling, 0);
}

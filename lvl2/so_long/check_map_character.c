/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:46:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/20 20:39:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_characters(char *buffer, char *allowed)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (buffer != NULL && buffer[i] != '\n' && buffer[i] != '\0')
	{
		found = 0;
		j = 0;
		while (allowed[j] != '\0')
		{
			if (buffer[i] == allowed[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			exit_map_error(buffer, 1, "Not allowed map characters");
		i++;
	}
}

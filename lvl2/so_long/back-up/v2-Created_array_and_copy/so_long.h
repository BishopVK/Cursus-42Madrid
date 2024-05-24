/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:33:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/24 14:08:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//libft
# include "libft/libft.h"

//ft_printf, ft_dprintf
# include "printf/ft_printf.h"

//get_next_line
# include "get_next_line/get_next_line.h"

//mlx
# include "minilibx-linux/mlx.h"

//open
# include <sys/types.h>

//close, read
# include <unistd.h>

//malloc, free, exit
# include <stdlib.h>

//perror
# include <stdio.h>

//strerror
# include <string.h>

typedef struct s_map_chars
{
	int	empty;
	int	wall;
	int	collectible;
	int	exit;
	int	player;
}	t_map_chars;

typedef struct s_map_array
{
	int		width;
	int		height;
	int		startX;
	int		startY;
	char	**map;
}	t_map_array;

/****************************************/
/*				parse.c					*/
/****************************************/
void	exit_map_error(char *buffer, char *message);
int		count_buffer_len(char *buffer);
int		read_map_lines(char *buffer, char *map);
void	read_map(char *map, t_map_chars *map_chars, t_map_array *map_array);
void	check_arg_extension(char *map);

/****************************************/
/*		check_map_characters.c			*/
/****************************************/
void	check_nbr_chars(char *buffer, t_map_chars *map_chars);
void	count_nbr_chars(char *buffer, t_map_chars *map_chars);
void	check_borders(char *buffer, int total_lines, int map_line);
int		read_for_check_borders(char *buffer, char *map, int map_lines,
			t_map_chars *map_chars);
void	check_map_characters(char *buffer, char *allowed);

/****************************************/
/*				array.c					*/
/****************************************/
void	free_array(t_map_array *s_map_array);
void	display_array(t_map_array *map_array);
void	initialize_array(char *buffer, t_map_array *map_array, int map_lines);
void	create_array(t_map_array *map_array);
void	read_to_create_array(char *map, t_map_array *map_array);

/****************************************/
/*			copy_of_array.c				*/
/****************************************/
char	**create_array_copy(t_map_array *map_array);

/****************************************/
/*			flood_fill.c				*/
/****************************************/
void	detect_player(char *buffer, t_map_array *map_array, int map_lines);
void	flood_fill(t_map_array	copy_array);

#endif
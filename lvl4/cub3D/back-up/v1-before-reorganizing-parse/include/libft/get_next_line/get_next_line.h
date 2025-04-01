/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:29:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/07 11:29:37 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//read, close
# include <unistd.h>

//open
# include <fcntl.h>

//printf
# include <stdio.h>

//malloc, free
# include <stdlib.h>

//NULL
# include <stddef.h>

//libft
# include "../libft.h"

//bool
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

/****************************************/
/*			get_next_line.c				*/
/****************************************/
char	*get_next_line(int fd, bool free_static);

#endif
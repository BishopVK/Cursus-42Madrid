/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:13:32 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/29 08:51:19 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

//OPEN_MAX (Max fd open)
# include <limits.h>

//strchr, strlen, strdup, strlcpy
//# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define COLOR_CYAN "\x1b[36m"
# define COLOR_RESET "\x1b[0m"

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
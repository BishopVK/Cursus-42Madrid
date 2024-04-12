/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:11:15 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/10 13:11:15 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//libft
#include "libft/libft.h"

//ft_printf, ft_dprintf
#include "printf/ft_printf.h"

//open, wait, waitpid
#include <sys/types.h>

//close, read, access, dup, dup2, execve, fork, pipe, unlink
#include <unistd.h>

//malloc, free, exit
#include <stdlib.h>

//perror
#include <stdio.h>

//strerror
#include <string.h>

//index pipe extremo escritura
#define READ_END 0

//index pipe extremo lectura
#define WRITE_END 1

/************************************/
/*				pipex.c				*/
/************************************/
int	main(int argc, char **argv, char **env);

#endif
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

/************************************/
/*				main.c				*/
/************************************/
int	main(int argc, char **argv);
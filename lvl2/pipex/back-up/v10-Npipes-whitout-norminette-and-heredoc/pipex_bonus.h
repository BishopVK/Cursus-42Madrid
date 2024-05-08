/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:12:50 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/24 12:12:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//libft
# include "libft/libft.h"

//ft_printf, ft_dprintf
# include "printf/ft_printf.h"

//open, wait, waitpid
# include <sys/types.h>

//close, read, access, dup, dup2, execve, fork, pipe, unlink
# include <unistd.h>

//malloc, free, exit
# include <stdlib.h>

//perror
# include <stdio.h>

//strerror
# include <string.h>

//wait, waitpid
# include <sys/wait.h>

//index pipe extremo escritura
# define READ_END 0

//index pipe extremo lectura
# define WRITE_END 1

# define BUFFER_SIZE 1024

typedef struct s_child_args
{
	char	**argv;
	int		*p_fd;
	int		*next_p_fd;
	char	**env;
	int		i;
}	t_child_args;

/************************************/
/*			pipex_bonus.c			*/
/************************************/
int		main(int argc, char **argv, char **env);

/************************************/
/*			pipex_utils_bonus.c		*/
/************************************/
void	free_split(char **split);
void	execute(char **split_argv, char *full_path, char **env);
char	*find_command_in_path(const char *command, char **path_list);
char	**get_path(char **env);
int		open_fd(char *file_name, int stdin_stdout);

/************************************/
/*			here_doc_bonus.c		*/
/************************************/
void	here_doc(char **argv);

/************************************/
/*			ft_split_awk_bonus.c	*/
/************************************/
char	**ft_split_awk(char const *s, char c);

/************************************/
/*			pipex_bonus_pipefd.c	*/
/************************************/
void	free_pipefd(char **pipefd, int num_cmds);
int		**alloc_pipefd(int num_cmds);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:17:24 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/11 19:17:24 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//libft
# include "libft/libft.h"

//ft_printf
# include "printf/ft_printf.h"

//get_next_line
# include "get_next_line/get_next_line_bonus.h"

//argc, argv
# include <stdlib.h>

//NULL
# include <stddef.h>

//strlen, memmove, strtok
# include <string.h>

/* typedef struct s_stack_node
{
	int					nb;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}					t_stack_node;

struct s_stack
{
	struct t_stack_node	*head;
	struct t_stack_node	*tail;
}					t_stack; */

/************************************************************/
/*							parse.c							*/
/************************************************************/
int				parse_argvs(int argc, char **argv);

/************************************************************/
/*						create_stack.c						*/
/************************************************************/
//t_stack_node	*stack_new_node(void *content);



#endif
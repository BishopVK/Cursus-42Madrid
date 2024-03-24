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

//INT_MAX, INT_MIN
# include <limits.h>

typedef struct s_stack_node
{
	int					nb;
	//int					orden; //orden en que deben estar ordenados
	struct s_stack_node	*next;
}					t_stack_node;

/* typedef struct s_stack
{
	struct t_stack_node	*head;
	struct t_stack_node	*tail;
}					t_stack; */

/************************************************************/
/*							parse.c							*/
/************************************************************/
int				allowed_chars(char *argv, char *allowed);
t_stack_node	*split_argvs(char *argv, int *total_strings,
					t_stack_node *new_node);
int				parse_argvs(int argc, char **argv, t_stack_node *stack_node_a,
					t_stack_node *stack_node_b);

/************************************************************/
/*						create_stack.c						*/
/************************************************************/
void			ft_del_node_content(void *content);
void			stack_clear(t_stack_node **node);
void			no_repeat_numbers(t_stack_node *new_node);
void			display(t_stack_node *new_node);
t_stack_node	*push(int nbr, t_stack_node *new_node);

/************************************************************/
/*						ft_atol.c							*/
/************************************************************/
long			ft_atol(const char *nptr);

/************************************************************/
/*						stack_utils.c						*/
/************************************************************/
int				stack_len(t_stack_node *new_node);

/************************************************************/
/*							swap.c							*/
/************************************************************/
void			swap(t_stack_node *node);
void			sa(t_stack_node *stack_node_a);
void			sb(t_stack_node *stack_node_b);
void			ss(t_stack_node *stack_node_a, t_stack_node *stack_node_b);

#endif
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
//# include <string.h>

//INT_MAX, INT_MIN, LLONG_MAX, LLONG_MIN
# include <limits.h>

typedef enum s_half
{
	UP,
	DOWN
}	t_half;

typedef struct s_stack_node
{
	int					nb;
	int					order;
	t_half				half;
	struct s_stack_node	*next;
}	t_stack_node;

/* typedef struct s_stack
{
	struct t_stack_node	*head;
	struct t_stack_node	*tail;
}					t_stack; */

/************************************************************/
/*							parse.c							*/
/************************************************************/
void			signs_checker(char *argv);
int				allowed_chars(char *argv, char *allowed);
t_stack_node	*split_argvs(char *argv, int *total_strings,
					t_stack_node *new_node, int *out_of_limits);
int				parse_argvs(int argc, char **argv, t_stack_node *stack_node_a,
					t_stack_node *stack_node_b);

/************************************************************/
/*						create_stack.c						*/
/************************************************************/
void			assign_half(t_stack_node *node);
void			assign_order(t_stack_node *node);
void			stack_clear(t_stack_node **node);
t_stack_node	*create_stack(int nbr, t_stack_node *new_node);

/************************************************************/
/*							ft_atol.c						*/
/************************************************************/
long			ft_atol(const char *nptr);

/************************************************************/
/*						ft_custom_atoi.c					*/
/************************************************************/
int				ft_custom_atoi(const char *nptr);

/************************************************************/
/*						sort_numbers.c						*/
/************************************************************/
void			only_one_element(t_stack_node *stack_node_a);
void			its_ordered(t_stack_node *stack_node_a);
void			sort_numbers(t_stack_node *stack_node_a,
					t_stack_node *stack_node_b);

/************************************************************/
/*						ft_custom_atoll.c					*/
/************************************************************/
long long int	ft_custom_atoll(const char *nptr);

/************************************************************/
/*						stack_utils.c						*/
/************************************************************/
int				stack_len(t_stack_node *new_node);
void			integer_number(int out_of_limits, t_stack_node *stack_node_a);
void			no_repeat_numbers(t_stack_node *stack_node_a);

/************************************************************/
/*							push.c							*/
/************************************************************/
void			push(t_stack_node **src, t_stack_node **dst);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

/************************************************************/
/*							swap.c							*/
/************************************************************/
void			swap(t_stack_node **node);
void			sa(t_stack_node **stack_node_a);
void			sb(t_stack_node **stack_node_b);
void			ss(t_stack_node **stack_node_a, t_stack_node **stack_node_b);

/************************************************************/
/*							rotate.c						*/
/************************************************************/
void			rotate(t_stack_node **node);
void			ra(t_stack_node **stack_node_a);
void			rb(t_stack_node **stack_node_b);
void			rr(t_stack_node **stack_node_a, t_stack_node **stack_node_b);

/************************************************************/
/*						reverse_rotate.c					*/
/************************************************************/
void			reverse_rotate(t_stack_node **node);
void			rra(t_stack_node **stack_node_a);
void			rrb(t_stack_node **stack_node_b);
void			rrr(t_stack_node **stack_node_a, t_stack_node **stack_node_b);

/************************************************************/
/*						sort_short.c						*/
/************************************************************/
void			short_algorithm(t_stack_node **stack_node_a,
					t_stack_node **stack_node_b);
void			sort_3_numbers(t_stack_node **stack_node_a);
void			sort_short(t_stack_node **stack_node_a,
					t_stack_node **stack_node_b);

/************************************************************/
/*						display.c							*/
/************************************************************/
void			display_by_order(t_stack_node *new_node);
void			display_order(t_stack_node *new_node);
void			display_half(t_stack_node *new_node);
void			display(t_stack_node *new_node);

/************************************************************/
/*						quicksort.c							*/
/************************************************************/
void quicksort(t_stack_node **stack_a, t_stack_node **stack_b, int len);

#endif
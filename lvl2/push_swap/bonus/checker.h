/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:56:55 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/11 11:56:55 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

//libft
# include "../libft/libft.h"

//ft_printf
# include "../printf/ft_printf.h"

//get_next_line
# include "../get_next_line/get_next_line.h"

//argc, argv
# include <stdlib.h>

//NULL
# include <stddef.h>

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
	int					rot;
	int					rev_rot;
	int					cost;
	int					pair_order;
	struct s_stack_node	*next;
}	t_stack_node;

/************************************************************/
/*							parse.c							*/
/************************************************************/
int				parse_argvs(int argc, char **argv, t_stack_node **stack_node_a);

/************************************************************/
/*						split_argvs.c						*/
/************************************************************/
t_stack_node	*split_argvs(char *argv, int *total_strings,
					t_stack_node *new_node, int *out_of_limits);

/************************************************************/
/*							stack.c							*/
/************************************************************/
void			display(t_stack_node *new_node);
void			stack_clear(t_stack_node **node);
t_stack_node	*create_stack(int nbr, t_stack_node *node);

/************************************************************/
/*					ft_custom_atoll.c						*/
/************************************************************/
long long int	ft_custom_atoll(const char *nptr);

/************************************************************/
/*							moves.c							*/
/************************************************************/
void			command(t_stack_node **a, t_stack_node **b, char *command);

/************************************************************/
/*							rotate.c						*/
/************************************************************/
void			ra(t_stack_node **stack_node_a);
void			rb(t_stack_node **stack_node_b);
void			rr(t_stack_node **stack_node_a, t_stack_node **stack_node_b);

/************************************************************/
/*						reverse_rotate.c					*/
/************************************************************/
void			rra(t_stack_node **stack_node_a);
void			rrb(t_stack_node **stack_node_b);
void			rrr(t_stack_node **stack_node_a, t_stack_node **stack_node_b);

/************************************************************/
/*							push.c							*/
/************************************************************/
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

/************************************************************/
/*							swap.c							*/
/************************************************************/
void			sa(t_stack_node **stack_node_a);
void			sb(t_stack_node **stack_node_b);
void			ss(t_stack_node **stack_node_a, t_stack_node **stack_node_b);

#endif
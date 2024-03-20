# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 07:56:47 by danjimen          #+#    #+#              #
#    Updated: 2024/03/20 14:30:29 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	push_swap.c \
				parse.c \
				create_stack.c \
				get_next_line/get_next_line_bonus.c \
				get_next_line/get_next_line_utils_bonus.c

OBJ			=	$(SRC:.c=.o)
HEADER		=	push_swap.h \
				get_next_line/get_next_line_bonus.h

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
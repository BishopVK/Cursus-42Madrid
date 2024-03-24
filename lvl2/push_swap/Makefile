# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 07:56:47 by danjimen          #+#    #+#              #
#    Updated: 2024/03/23 21:23:21 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definición de colores
COLOR_CYAN := "\x1b[36m"
COLOR_GREEN := "\x1b[32m"
COLOR_RESET := "\x1b[0m"

# Macro para imprimir un mensaje en color cyan
define print_cyan
	@echo $(COLOR_CYAN)$1$(COLOR_RESET)
endef

# Macro para imprimir un mensaje en color green
define print_green
	@echo $(COLOR_GREEN)$1$(COLOR_RESET)
endef

NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	push_swap.c \
				parse.c \
				create_stack.c \
				ft_atol.c \
				stack_utils.c \
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
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	$(call print_cyan,"Compiled push_swap")

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@rm -f $(OBJ)
	$(call print_green,"Cleaned object files of push_swap")

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	$(call print_green,"Cleaned the executable push_swap")

re: fclean all

.PHONY: all clean fclean re
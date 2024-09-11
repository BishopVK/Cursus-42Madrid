# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 07:56:47 by danjimen          #+#    #+#              #
#    Updated: 2024/09/11 14:03:04 by danjimen &       ###   ########.fr        #
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

PUSH_NAME	=	push_swap
CHECK_NAME	=	checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	push_swap.c \
				parse.c \
				create_stack.c \
				stack_utils.c \
				ft_custom_atoll.c \
				push.c \
				swap.c \
				rotate.c \
				reverse_rotate.c \
				sort_numbers.c \
				sort_short.c \
				display.c \
				turk.c \
				turk_extra.c \
				determine_moves.c \
				return_b_to_a.c \
				get_next_line/get_next_line_bonus.c \
				get_next_line/get_next_line_utils_bonus.c

BONUS_DIR	=	bonus
GNL_DIR		=	bonus/get_next_line
SRC_BONUS	=	$(BONUS_DIR)/checker.c \
				$(BONUS_DIR)/ft_custom_atoll.c \
				$(BONUS_DIR)/moves.c \
				$(BONUS_DIR)/parse.c \
				$(BONUS_DIR)/push.c \
				$(BONUS_DIR)/reverse_rotate.c \
				$(BONUS_DIR)/rotate.c \
				$(BONUS_DIR)/split_argvs.c \
				$(BONUS_DIR)/stack.c \
				$(BONUS_DIR)/swap.c \
				$(GNL_DIR)/get_next_line.c \
				$(GNL_DIR)/get_next_line_utils.c \

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

HEADER		=	push_swap.h \
				get_next_line/get_next_line_bonus.h \
				bonus/get_next_line/get_next_line_bonus.h

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

all: $(PUSH_NAME) $(CHECK_NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(PUSH_NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(OBJ) $(LIBFT) $(PRINTF) -o $(PUSH_NAME)
	$(call print_cyan,"Compiled push_swap")

$(CHECK_NAME): $(OBJ_BONUS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) $(OBJ_BONUS) $(LIBFT) $(PRINTF) -o $(CHECK_NAME)
	$(call print_cyan,"Compiled checker")

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	$(call print_green,"Cleaned object files of push_swap and checker")

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(PUSH_NAME)
	@rm -f $(CHECK_NAME)
	$(call print_green,"Cleaned the executable push_swap and checker")

re: fclean all

.PHONY: all clean fclean re
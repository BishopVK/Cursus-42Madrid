# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 13:35:22 by danjimen          #+#    #+#              #
#    Updated: 2024/06/13 09:01:12 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors definition
COLOR_CYAN := "\033[36m"
COLOR_GREEN := "\033[32m"
COLOR_RESET := "\033[0m"

# Macro to print a message in cyan color
define print_cyan
	@echo $(COLOR_CYAN)$1$(COLOR_RESET)
endef

# Macro to print a message in green color
define print_green
	@echo $(COLOR_GREEN)$1$(COLOR_RESET)
endef

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
SRC			=	so_long.c \
				parse.c \
				check_map_character.c \
				array.c \
				copy_of_array.c \
				flood_fill.c \
				game.c \
				hooks.c \
				movements.c

OBJ			=	$(SRC:.c=.o)

BONUS_SRC	=	so_long_bonus.c

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

GNL_SRC		=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

GNL_OBJ		=	$(GNL_SRC:.c=.o)

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

MINILIBX_DIR	=	minilibx-linux
MINILIBX		=	$(MINILIBX_DIR)/libmlx_Linux.a

#OPENGL_DIR	=	printf
#OPENGL		=	$(OPENGL_DIR)/libftprintf.a

all: $(NAME)

bonus: $(NAME)_bonus

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

#$(OPENGL):
#	@$(MAKE) -C $(OPENGL_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJ) $(GNL_OBJ)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MINILIBX_DIR) $(OBJ) $(GNL_OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) -L$(MINILIBX_DIR) -lX11 -lXext -lbsd -o $(NAME)
	$(call print_cyan,"Compiled so_long")

#$(NAME)_bonus: $(LIBFT) $(PRINTF) $(BONUS_OBJ) # Rule for compiling with bonus items
#	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MINILIBX_DIR) $(BONUS_OBJ) $(GNL_OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME)
#	$(call print_cyan,"Compiled so_long (bonus)")

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MINILIBX_DIR) -c $< -o $@

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean
	@$(MAKE) -s -C $(MINILIBX_DIR) clean
	@rm -f $(OBJ) $(GNL_OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@$(MAKE) -s -C $(MINILIBX_DIR) clean
	@rm -f $(NAME)
	$(call print_green,"Cleaned the executable so_long")

re: fclean all

.PHONY: all clean fclean re

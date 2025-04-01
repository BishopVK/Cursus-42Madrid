# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 13:35:22 by danjimen          #+#    #+#              #
#    Updated: 2025/04/01 17:16:11 by danjimen         ###   ########.fr        #
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

NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3

SRC_DIR		=	src
PARSE_DIR	=	src/parse

SRC			=	$(SRC_DIR)/cub3d.c \
				$(PARSE_DIR)/parse.c \
				$(PARSE_DIR)/clean.c \
				$(PARSE_DIR)/debug.c \
				$(PARSE_DIR)/detect_elements.c \
				$(PARSE_DIR)/check_elements.c \
				$(PARSE_DIR)/map.c

OBJ			=	$(SRC:.c=.o)

LIBFT_DIR	=	include/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

MINILIBX_DIR	=	include/minilibx-linux
MINILIBX		=	$(MINILIBX_DIR)/libmlx_Linux.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) $(OBJ) $(LIBFT) $(MINILIBX) -L$(MINILIBX_DIR) -lX11 -lXext -lbsd -o $(NAME)
	$(call print_cyan,"Compiled cub3D")

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MINILIBX_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MINILIBX_DIR) clean
	@rm -f $(NAME)
	$(call print_green,"Cleaned the executable cub3D")

re: fclean all

rc: re
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MINILIBX_DIR) clean
	@rm -f $(OBJ)

r:	rc
	./$(NAME) $(ARG)

valgrind:	rc
	valgrind --leak-check=full ./$(NAME) $(ARG)

.PHONY: all clean fclean re
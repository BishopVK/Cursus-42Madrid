# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 13:35:22 by danjimen          #+#    #+#              #
#    Updated: 2024/05/16 13:35:22 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definición de colores
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
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	so_long.c

OBJ			=	$(SRC:.c=.o)

BONUS_SRC	=	so_long_bonus.c

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

MINILIBX_DIR	=	minilibx-linux
MINILIBX		=	$(MINILIBX_DIR)/libmlx.a

OPENGL_DIR	=	printf
OPENGL		=	$(OPENGL_DIR)/libftprintf.a

all: $(NAME)

bonus: $(NAME)_bonus

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)

$(MINILIBX):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	$(call print_cyan,"Compiled pipex")

$(NAME)_bonus: $(LIBFT) $(PRINTF) $(BONUS_OBJ) # Rule for compiling with bonus items
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(BONUS_OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	$(call print_cyan,"Compiled pipex (bonus)")

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	$(call print_green,"Cleaned the executable pipex")

re: fclean all

.PHONY: all clean fclean re

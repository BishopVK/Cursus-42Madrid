# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 13:11:23 by danjimen          #+#    #+#              #
#    Updated: 2024/04/10 13:11:23 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definición de colores
COLOR_CYAN := "\033[36m"
COLOR_GREEN := "\033[32m"
COLOR_RESET := "\033[0m"

# Macro para imprimir un mensaje en color cyan
define print_cyan
	@echo $(COLOR_CYAN)$1$(COLOR_RESET)
endef

# Macro para imprimir un mensaje en color green
define print_green
	@echo $(COLOR_GREEN)$1$(COLOR_RESET)
endef

NAME		=	pipex
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	pipex.c \
				pipex_utils.c \
				ft_split_awk.c

OBJ			=	$(SRC:.c=.o)

BONUS_SRC	=	pipex_bonus.c \
				pipex_utils_bonus.c \
				here_doc_bonus.c \
				ft_split_awk_bonus.c \
				pipex_extra_bonus.c

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

all: $(NAME)

bonus: $(NAME)_bonus

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	$(call print_cyan,"Compiled pipex")

$(NAME)_bonus: $(LIBFT) $(PRINTF) $(BONUS_OBJ) # Regla para compilar con objetos bonus
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(BONUS_OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	$(call print_cyan,"Compiled pipex (bonus)")

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	$(call print_green,"Cleaned the executable pipex")

re: fclean all

.PHONY: all clean fclean re

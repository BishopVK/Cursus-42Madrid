# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 07:52:00 by danjimen          #+#    #+#              #
#    Updated: 2024/06/26 08:19:50 by danjimen         ###   ########.fr        #
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

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

SRC_DIR		=	src
SRC			=	$(SRC_DIR)/philo.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	$(call print_cyan, "Compiled philo")

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	$(call print_green, "Cleaned philo objects")

fclean: clean
	@rm -f $(NAME)
	$(call print_green, "Cleaned philo executable")

re: fclean all

.PHONY: all clean fclean re
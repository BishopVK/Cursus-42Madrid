# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 09:19:38 by danjimen          #+#    #+#              #
#    Updated: 2024/10/28 07:55:57 by danjimen &       ###   ########.fr        #
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

NAME			=	philo

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=thread -g3

SRC_DIR			=	src
FUNCTIONS_DIR	=	$(SRC_DIR)/functions
SRC				=	$(SRC_DIR)/philo.c \
					$(SRC_DIR)/parse.c \
					$(SRC_DIR)/routine.c \
					$(SRC_DIR)/actions.c \
					$(FUNCTIONS_DIR)/ft_atoi.c \
					$(FUNCTIONS_DIR)/ft_atol.c \
					$(FUNCTIONS_DIR)/ft_isdigit.c

OBJ				=	$(SRC:.c=.o)

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
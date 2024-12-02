# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 09:19:38 by danjimen          #+#    #+#              #
#    Updated: 2024/11/21 12:19:19 by danjimen         ###   ########.fr        #
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
CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=thread

SRC_DIR			=	src
FUNCTIONS_DIR	=	$(SRC_DIR)/functions
ACTIONS_DIR		=	$(SRC_DIR)/actions
ROUTINE_DIR		=	$(SRC_DIR)/routine
SRC				=	$(SRC_DIR)/philo.c \
					$(SRC_DIR)/parse.c \
					$(SRC_DIR)/utils.c \
					$(ROUTINE_DIR)/philo_routine.c \
					$(ROUTINE_DIR)/referee_routine.c \
					$(ACTIONS_DIR)/think.c \
					$(ACTIONS_DIR)/eat.c \
					$(ACTIONS_DIR)/sleep.c \
					$(ACTIONS_DIR)/take_forks.c \
					$(ACTIONS_DIR)/leave_forks.c \
					$(ACTIONS_DIR)/print_action.c \
					$(FUNCTIONS_DIR)/ft_atoi.c \
					$(FUNCTIONS_DIR)/ft_atol.c \
					$(FUNCTIONS_DIR)/ft_isdigit.c \
					$(FUNCTIONS_DIR)/ft_strcmp.c

OBJ				=	$(SRC:.c=.o)

all: $(NAME)

rc: re
	@rm -f $(OBJ)
	$(call print_green, "Cleaned philo objects")

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
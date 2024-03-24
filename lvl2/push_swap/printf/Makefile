# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 21:00:56 by danjimen          #+#    #+#              #
#    Updated: 2024/01/30 21:00:56 by danjimen         ###   ########.fr        #
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

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	ft_printf.c \
				ft_putchar_printf.c \
				ft_putnbr_printf.c \
				ft_putstr_printf.c \
				ft_putunbr_printf.c \
				ft_tohex_printf.c

OBJ			=	$(SRC:.c=.o)
HEADER		=	ft_printf.h

#LIBFT_DIR	=	libft
#LIBFT		=	$(LIBFT_DIR)/libft.a

#all: $(LIBFT) $(NAME)
all: $(NAME)

#$(LIBFT):
#	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
#	$(CC) $(CFLAGS) -c -I$(LIBFT_INC) $(SRC)
#	ar rc $(NAME) $(OBJ) $(LIBFT)
#	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	$(call print_cyan,"Compiled printf")

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
#	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	$(call print_green,"Cleaned object files of printf")

fclean: clean
#	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	$(call print_green,"Cleaned the library libftprintf.a")

re: fclean all

.PHONY: all clean fclean re
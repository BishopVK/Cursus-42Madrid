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
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
#	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
#	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
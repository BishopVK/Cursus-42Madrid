# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 08:22:03 by danjimen          #+#    #+#              #
#    Updated: 2024/12/03 11:33:12 by danjimen         ###   ########.fr        #
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

NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_atol.c \
				ft_strcmp.c

OBJ			=	$(SRC:.c=.o)
		
BONUS_SRC	=	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	$(call print_cyan,"Compiled libft")

bonus: $(BONUS_OBJ) libft.h
	@ar rc $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)
	$(call print_cyan,"Compiled libft bonus")

%.o: %.c libft.h
#	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	$(call print_green,"Cleaned object files of libft")

fclean: clean
	@rm -f $(NAME) $(BONUS_OBJ)
	$(call print_green,"Cleaned the library libft.a")

re: fclean all

.PHONY: all clean fclean re
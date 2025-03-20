# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 22:25:26 by danjimen          #+#    #+#              #
#    Updated: 2025/03/20 00:06:03 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex01

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			Fixed.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

rc: re
	rm -f $(OBJ)

r: rc
	./$(NAME)

.PHONY: all clean fclean re rc r
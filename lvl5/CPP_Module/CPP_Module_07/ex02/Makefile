# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 23:25:27 by danjimen          #+#    #+#              #
#    Updated: 2025/06/04 08:40:47 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Array

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

OBJ			=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

rc: re
	rm -f $(OBJ)

r:	rc
	./$(NAME)

valgrind:	rc
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re rc r
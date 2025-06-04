# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 16:06:22 by danjimen          #+#    #+#              #
#    Updated: 2025/06/04 11:39:44 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	MutantStack

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

OBJ			=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Manual dependency
Span.o: Span.cpp Span.hpp

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

rc:	re
	rm -f $(OBJ)

r:	rc
	./$(NAME)

valgrind:	rc
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re rc r valgrind
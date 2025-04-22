# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 08:58:19 by danjimen          #+#    #+#              #
#    Updated: 2025/04/22 22:33:38 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	convert

CPP		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			ScalarConverter.cpp

OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

rc: re
	rm -f $(OBJ)

r:	rc
	./$(NAME) $(ARG)

valgrind:	rc
	valgrind --leak-check=full ./$(NAME) $(ARG)

.PHONY: all clean fclean re rc r
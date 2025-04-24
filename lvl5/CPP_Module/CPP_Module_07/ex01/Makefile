# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 23:25:27 by danjimen          #+#    #+#              #
#    Updated: 2025/04/25 00:25:48 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex01

CPP		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp

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
	./$(NAME)

valgrind:	rc
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re rc r
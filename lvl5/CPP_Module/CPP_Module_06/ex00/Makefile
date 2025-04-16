# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 08:58:19 by danjimen          #+#    #+#              #
#    Updated: 2025/04/16 23:14:20 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	convert

CPP		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			ScalarConverter.cpp

OBJ		=	$(SRC:.cpp=.o)

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

.PHONY: all clean fclean re rc r valgrind
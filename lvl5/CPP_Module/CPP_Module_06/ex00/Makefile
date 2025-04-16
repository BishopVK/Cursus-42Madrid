# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 08:58:19 by danjimen          #+#    #+#              #
#    Updated: 2025/04/16 22:38:18 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Conversion_of_scalar_types

CPP		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			ScalarConverter.cpp

OBJ		=	$(SRC:.cpp=.o)

all		=	$(NAME)

$(NAME):	$(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

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
	--leak-check=full ./$(NAME)

.PHONY: all clean fclean re rc r valgrind
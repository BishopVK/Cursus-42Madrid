# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 00:58:33 by danjimen          #+#    #+#              #
#    Updated: 2025/04/21 19:37:29 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Sed_is_for_losers

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			Replacer.cpp \

OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

rc: re
	rm -f $(OBJ)

r:	rc
	./$(NAME)

.PHONY: all clean fclean re rc r
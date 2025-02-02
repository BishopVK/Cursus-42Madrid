# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 17:41:07 by danjimen          #+#    #+#              #
#    Updated: 2025/02/02 11:49:02 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	BraiiiiiiinnnzzzZ

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			Zombie.cpp \
			zombieHorde.cpp

OBJ		=	$(SRC:.cpp=.o)

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
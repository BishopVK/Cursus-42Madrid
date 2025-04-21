# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 17:41:07 by danjimen          #+#    #+#              #
#    Updated: 2025/04/21 11:16:54 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	BraiiiiiiinnnzzzZ

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp

OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

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
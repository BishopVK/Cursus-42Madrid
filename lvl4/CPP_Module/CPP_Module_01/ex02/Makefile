# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 17:41:07 by danjimen          #+#    #+#              #
#    Updated: 2025/04/21 11:17:06 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	HI_THIS_IS_BRAIN

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp

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
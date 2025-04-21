# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 20:28:40 by danjimen          #+#    #+#              #
#    Updated: 2025/04/21 19:45:02 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	harlFilter

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			Harl.cpp

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

re:	fclean all

rc:	re
	rm -f $(OBJ)

r:	rc
	./$(NAME)

.PHONE: all clean fclean re rc r
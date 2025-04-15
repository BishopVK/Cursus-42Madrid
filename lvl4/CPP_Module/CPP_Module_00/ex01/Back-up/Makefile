# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 10:38:00 by danjimen          #+#    #+#              #
#    Updated: 2025/01/26 13:43:21 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CPP		=	c++
FLAGS	=	-Wall -Wextra -Wno-used -Werror -std=c++98

SRC		=	main.cpp \
			Contact.cpp \
			Phonebook.cpp

OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

rc: re
	@rm -f $(OBJ)

r: rc
	./$(NAME)

.PHONY: all clean fclean re
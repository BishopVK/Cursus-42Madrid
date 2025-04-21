# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 10:38:00 by danjimen          #+#    #+#              #
#    Updated: 2025/04/21 11:19:21 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			Contact.cpp \
			Phonebook.cpp

OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

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
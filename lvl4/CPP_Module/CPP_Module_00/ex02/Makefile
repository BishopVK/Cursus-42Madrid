# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 10:38:00 by danjimen          #+#    #+#              #
#    Updated: 2025/04/21 12:25:18 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Account

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	tests.cpp \
			Account.cpp

OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

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
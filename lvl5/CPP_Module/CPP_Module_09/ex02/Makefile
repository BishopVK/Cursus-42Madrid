# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 23:38:18 by danjimen          #+#    #+#              #
#    Updated: 2025/06/09 01:20:10 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe

CPP		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			PmergeMe.cpp

OBJ		=	$(SRC:.cpp=.o)

%.o:	%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

rc:	re
	rm -f $(OBJ)

.PHONY: all clean fclean re rc r valgrind


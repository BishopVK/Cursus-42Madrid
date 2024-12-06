# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 10:38:00 by danjimen          #+#    #+#              #
#    Updated: 2024/12/06 18:35:26 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CPP		=	c++
FLAGS	=	-Wall -Wextra -Wno-used -Werror -std=c++98

SOURCES	=	main.cpp #phonebook.cpp

OBJECTS	=	$(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(CPP) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
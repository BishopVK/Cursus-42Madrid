# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 10:38:00 by danjimen          #+#    #+#              #
#    Updated: 2025/04/21 12:17:49 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SOURCES	=	megaphone.cpp

OBJECTS	=	$(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(CPP) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
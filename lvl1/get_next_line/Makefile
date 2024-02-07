# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 11:03:18 by danjimen          #+#    #+#              #
#    Updated: 2024/02/07 11:03:18 by danjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Librería a crear
NAME		=	get_next_line.a

# Compilador a utilizar
CC			=	gcc

# Flags de compilación
CFLAGS		=	-Wall -Wextra -Werror

# Ficheros a compilar
SRC			=	get_next_line.c \
				get_next_line_utils.c

# Definición de la lista de objetos creados a partir de SRC
OBJ			=	$(SRC:.c=.o)

# Cabecera
HEADER		=	get_next_line.h

# Objetivo predeterminado: construir el archivo objetivo
all: $(NAME)

# Regla para construir el archivo objetivo. Compilar los archivos objeto y crear el archivo objetivo. Crear la biblioteca estática. Indexar la biblioteca
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# Regla de compilación de archivos fuente en archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto
clean:
	rm -f $(OBJ)

# Regla para limpiar los archivos objeto y el archivo objetivo
fclean: clean
	rm -f $(NAME)

# Regla para reconstruir el proyecto
re: fclean all

# Objetivos que no son archivos
.PHONY: all clean fclean re
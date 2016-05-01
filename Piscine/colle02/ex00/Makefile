# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ypasquie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/25 13:21:06 by malexand          #+#    #+#              #
#    Updated: 2015/07/26 21:52:45 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = colle-2
SRC = src/main.c src/colle00.c src/colle01.c src/colle02.c src/colle03.c src/colle04.c
FLAGS = -Wall -Wextra -Werror
INCLUDE = include/
OBJ = main.o colle00.o colle01.o colle02.o colle03.o colle04.o
LIB = libft.a

all: $(NAME)
	
$(NAME):
	$(CC)  $(FLAGS) -c $(SRC)
	$(CC)  $(FLAGS) $(OBJ) $(LIB) -I $(INCLUDE) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

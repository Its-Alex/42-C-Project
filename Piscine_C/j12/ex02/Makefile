# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/23 09:22:02 by malexand          #+#    #+#              #
#    Updated: 2015/07/24 23:34:17 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

NAME = ft_tail
SRC = srcs/ft_tail.c
OBJ = $(SRC:.c=.o)
LIB = libft.a
FLAGS = -Wall -Wextra -Werror

all: obj
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
obj:
	gcc -o $(OBJ) -c $(SRC)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 11:02:13 by malexand          #+#    #+#              #
#    Updated: 2015/07/23 11:29:57 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_swap.c srcs/ft_strlen.c
SRCO = ft_putchar.o ft_putstr.o ft_strcmp.o ft_swap.o ft_strlen.o
INCLUDE = includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(INCLUDE)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)
clean: 
	rm -rf $(SRCO)
fclean: clean
	rm -rf $(NAME)
re: fclean all

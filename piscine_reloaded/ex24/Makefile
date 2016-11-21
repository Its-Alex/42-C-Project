# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:22:10 by malexand          #+#    #+#              #
#    Updated: 2016/11/03 11:22:32 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAG = -Wall -Werror -Wextra

SRCS = 	srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_swap.c \
		srcs/ft_strlen.c 

OBJS = 	ft_putchar.o \
		ft_putstr.o \
		ft_strcmp.o \
		ft_swap.o \
		ft_strlen.o 


all:$(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@

$(OBJS): $(SRCS)
	gcc $(CFLAG) -c $(SRCS) -I.incs/

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

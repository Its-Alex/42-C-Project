# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 13:22:56 by malexand          #+#    #+#              #
#    Updated: 2016/11/03 16:48:29 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

CFLAG = -Wall -Werror -Wextra

SRCS = 	srcs/ft_display_file.c

OBJS = 	ft_display_file.o


all:$(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAG) $(SRCS) -I.incs/ -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

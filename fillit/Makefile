# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by alex              #+#    #+#              #
#    Updated: 2016/04/07 20:53:19 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
DEBUG = no
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SDIR =		./srcs/
SRCS =		$(shell ls srcs/)
SRCC =		$(addprefix $(SDIR),$(SRCS))

IDIR =		./incs/
INCS =		$(shell ls incs/)
INCC =		$(addprefix $(IDIR),$(INCS))

INCLUDE = -I./incs/

ODIR =		./objs/

ifeq ($(CC), gcc)
	OBJS =		$(SRCS:.c=.o)
	OBCC =		$(addprefix $(ODIR),$(OBJS))
else
	OBJS =		$(SRCS:.cpp=.o)
	OBCC =		$(addprefix $(ODIR),$(OBJS))
endif

all: $(NAME)

$(NAME): $(OBCC)
	@make -C ./Libft
	@echo "Génération du programme..."
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) ./Libft/libft.a

$(ODIR)%.o: $(SDIR)%.c
	@echo "Génération du fichier objet $@..."
	@$(CC) $^ $(CFLAG) -c -o $@

clean:
	@echo "Suppression des fichiers objets et des fichiers résiduels du programme..."
	@make -C ./Libft clean
	@rm -f $(OBCC)

fclean: clean
	@echo "Suppression de l'exécutable..."
	@make -C ./Libft fclean
	@rm -f $(NAME)

re: fclean all

run: re
	@./$(NAME)


.PHONY: all clean fclean re run

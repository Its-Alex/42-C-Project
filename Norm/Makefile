# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by alex              #+#    #+#              #
#    Updated: 2016/04/01 21:02:43 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
CYA =		\033[36m
STD =		\033[39m


NAME = Norminette
DEBUG = no
CC = gcc

LIB = yes

ifeq ($(DEBUG), yes)
	CFLAGS = -O3 -g -Wall -Werror -Wextra
else
	CFLAGS = -O3 -Wall -Werror -Wextra
endif


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
	@echo "Génération du programme..."
	@make -C ./lib/
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) ./lib/lib.a

$(ODIR)%.o: $(SDIR)%.c
	@echo "Génération du fichier objet $@..."
	@gcc $^ $(CFLAG) -c -o $@

clean:
	@echo "Suppression des fichiers objets et des fichiers résiduels du programme..."
	@rm -f $(OBCC)

fclean: clean
	@echo "Suppression de l'exécutable..."
	make -C ./lib/ fclean
	@rm -f $(NAME)

re: fclean all

run: re
	@./$(NAME)


.PHONY: all clean fclean re run

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
MKDIR_P = mkdir -p

OUT_DIR = objs

SDIR =		./srcs/
SRCS =		checks.c create_tetri.c define_result.c ft_putchar.c ft_putstr.c ft_strjoin_free.c ft_strlen.c ft_strsub.c main.c resolve.c
SRCC =		$(addprefix $(SDIR),$(SRCS))

IDIR =		./incs/
INCS =		fillit.h
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

all: directories $(NAME)

$(NAME): $(OBCC)
	@echo "Génération du programme..."
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE)

$(ODIR)%.o: $(SDIR)%.c
	@echo "Génération du fichier objet $@..."
	@$(CC) $^ $(CFLAGS) -c -o $@

directories: ${OUT_DIR}

${OUT_DIR}:
	@${MKDIR_P} ${OUT_DIR}

clean:
	@echo "Suppression des fichiers objets et des fichiers résiduels du programme..."
	@rm -f $(OBCC)

fclean: clean
	@echo "Suppression de l'exécutable..."
	@rm -f $(NAME)

re: fclean all

run: re
	@./$(NAME) extern_file.txt


.PHONY: all clean fclean re run directories

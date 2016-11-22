# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by alex              #+#    #+#              #
#    Updated: 2016/11/22 16:26:57 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
DEBUG = no
CC = clang
CFLAGS = -Wall -Werror -Wextra -pedantic
MKDIR_P = mkdir -p

OUT_DIR = objs
SRC_DIR = srcs
INC_DIR = incs

SDIR =		./srcs/
SRCS =		$(shell ls srcs/)
SRCC =		$(addprefix $(SDIR),$(SRCS))

IDIR =		./incs/
INCS =		$(shell ls incs/)
INCC =		$(addprefix $(IDIR),$(INCS))

INCLUDE = -I./incs/

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

all: directories $(NAME)

$(NAME): $(OBCC)
	@make -C ./libft
	@echo "Génération du programme..."
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) ./libft/libft.a

$(ODIR)%.o: $(SDIR)%.c
	@echo "Génération du fichier objet $@..."
	@$(CC) $^ $(CFLAGS) -c -o $@

directories: ${OUT_DIR} ${SRC_DIR} ${INC_DIR}

${OUT_DIR}:
	@${MKDIR_P} ${OUT_DIR}

${SRC_DIR}:
	@${MKDIR_P} ${SRC_DIR}

${INC_DIR}:
	@${MKDIR_P} ${INC_DIR}

clean:
	@echo "Suppression des fichiers objets et des fichiers résiduels du programme..."
	@rm -f $(OBCC)

fclean: clean
	@echo "Suppression de l'exécutable..."
	@rm -f $(NAME)

re: fclean all

run: re
	@./$(NAME)

cleanlib:
	@make -C ./libft fclean


.PHONY: all clean fclean re run directories cleanlib

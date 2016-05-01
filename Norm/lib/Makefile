# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by alex              #+#    #+#              #
#    Updated: 2016/03/20 15:47:15 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

CFLAG = -O3 -Wall -Werror -Wextra

SDIR =		./srcs/
SRCS =		$(shell ls srcs/)
SRCC =		$(addprefix $(SDIR),$(SRCS))

IDIR =		./incs/
INCS =		$(shell ls incs/)
INCC =		$(addprefix $(IDIR),$(INCS))

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))


all:$(NAME)

$(NAME): $(OBCC)
	@echo "Génération de la lib..."
	@ar rc -o $@ $(OBCC)
	@ranlib $@

$(ODIR)%.o: $(SDIR)%.c
	@echo "Génération du fichier objet $@..."
	@gcc $^ $(CFLAG) -c -o $@ -I.incs/

clean:
	@echo "Suppression des fichiers objets et des fichiers résiduels du programme..."
	@rm -f $(OBCC)

fclean: clean
	@echo "Suppression de l'exécutable..."
	@rm -f $(NAME)

re: fclean all

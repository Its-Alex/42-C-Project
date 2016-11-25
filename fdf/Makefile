# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2016/11/25 14:29:04 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
DEBUG = yes
CC = gcc
OS := $(shell uname -s)
MKDIR_P = mkdir -p

ifeq ($(DEBUG), yes)
	CFLAGS = -g -ggdb -Wall -Werror -Wextra
else
	CFLAGS = -Wall -Werror -Wextra
endif
LFLAGS = libft/libft.a mlx/libmlx.a -lmlx -framework OpenGL -framework AppKit

OUT_DIR = objets
SRC_DIR = sources
INC_DIR = includes

SDIR =		./sources/
SRCS =		$(shell ls sources/)
SRCC =		$(addprefix $(SDIR),$(SRCS))

INCLUDE = -I includes

ODIR =		./objets/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

all: directories $(NAME)

$(NAME): $(OBCC)
ifeq ($(OS), Linux)
	@make -C ./libft
	@make -C ./mlx
	@clang $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo "Build $(NAME) ✅"
else
	@make -C ./libft
	@make -C ./mlx
	@echo "\x1B[31m\c"
	@norminette sources/* includes/* | grep -B 1 "Error" || true
	@echo "\x1B[0m\c"
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo "Build $(NAME) ✅"
endif

$(ODIR)%.o: $(SDIR)%.c
	@$(CC) $^ $(CFLAGS) -c -o $@ $(INCLUDE)

directories: ${OUT_DIR} ${SRC_DIR} ${INC_DIR}

${OUT_DIR}:
	@${MKDIR_P} ${OUT_DIR}

${SRC_DIR}:
	@${MKDIR_P} ${SRC_DIR}

${INC_DIR}:
	@${MKDIR_P} ${INC_DIR}

clean:
	@rm -f $(OBCC)
	@echo "Deleting compilation files ✅"

fclean: clean
	@rm -f $(NAME)
	@echo "Deleting $(NAME) ✅"

re: fclean all

run: re
	@./$(NAME) maps/42.fdf

cleanlib:
	@make -C ./libft fclean
	@make -C ./mlx clean


.PHONY: all clean fclean re run directories cleanlib

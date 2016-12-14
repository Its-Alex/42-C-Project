# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2016/12/14 14:59:34 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
DEBUG = no
CC = clang
OS := $(shell uname -s)
MKDIR_P = mkdir -p

ifeq ($(DEBUG), yes)
	CFLAGS = -Wall -Werror -Wextra -g -ggdb -fsanitize=address -v
else
	CFLAGS = -Wall -Werror -Wextra
endif
ifeq ($(OS), Linux)
	LFLAGS = libft/libft.a mlx/libmlx_Linux.a -lXext -lX11
else
	LFLAGS = libft/libft.a -lmlx -framework OpenGL -framework AppKit
endif

OUT_DIR = objets
SRC_DIR = sources
INC_DIR = includes

SDIR =		./sources/
SRCS =		check.c event.c image.c main.c menu.c parse.c init.c mlx_put.c
SRCC =		$(addprefix $(SDIR),$(SRCS))

INCLUDE = -I includes

ODIR =		./objets/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

all: directories $(NAME)

$(NAME): $(OBCC)
ifeq ($(OS), Linux)
	@make -C ./libft
	clang $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo "Build $(NAME) ✅"
else
	@make -C ./libft
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
	@make -C ./libft clean
	@rm -rf $(OUT_DIR)
	@echo "Deleting compilation files ✅"

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)
	@echo "Deleting $(NAME) ✅"

re: fclean all

run: all
	@./$(NAME) maps/42.fdf

cleanlib:
	@make -C ./libft fclean


.PHONY: all clean fclean re run directories cleanlib

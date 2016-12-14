# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2016/12/14 15:10:53 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
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
	LFLAGS = libft/libft.a mlx/libmlx_Linux.a -lXext -lX11 -DLinux
else
	LFLAGS = libft/libft.a -lmlx -framework OpenGL -framework AppKit
endif

OUT_DIR = objets
SRC_DIR = sources
INC_DIR = includes

SDIR =		./sources/
SRCS =		$(shell ls sources)
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
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS) -lpthread -D_REENTRANT
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
	@rm -rf $(OUT_DIR)
	@make -C ./libft fclean
	@echo "Deleting compilation files ✅"

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@echo "Deleting $(NAME) ✅"

re: fclean all

run: all
	@./$(NAME) Mandelbrot

cleanlib:
	@make -C ./libft fclean


.PHONY: all clean fclean re run directories cleanlib

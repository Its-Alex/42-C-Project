# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2017/01/30 22:30:23 by skyzie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fractol

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
	LFLAGS = libft/libft.a -lmlx -lXext -lX11 -DLinux -lpthread -D_REENTRANT
else
	LFLAGS = libft/libft.a -lmlx -framework OpenGL -framework AppKit -lpthread -D_REENTRANT
endif

OUT_DIR = objets
SRC_DIR = sources
INC_DIR = includes

SDIR =		./sources/
SRCS =		do_frac.c events_key.c events_loop.c events_mouse.c image.c init.c \
			main.c thread_end.c thread_start.c zoom.c
SRCC =		$(addprefix $(SDIR),$(SRCS))

INCLUDE = -I./includes -I/usr/include/mlx

ODIR =		./objets/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

all: directories $(EXEC)

$(EXEC): $(OBCC)
ifeq ($(OS), Linux)
	@echo "\x1B[39mLibft:\x1B[0m\n"
	@make -C ./libft
	@echo "\x1B[39m$(EXEC):\x1B[0m"
	clang $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
else
	@echo "\x1B[39mLibft:\x1B[0m\n"
	@make -C ./libft
	@echo "\x1B[39m$(EXEC):\x1B[0m"
	@echo "\x1B[31m\c"
	@norminette sources/* includes/* | grep -B 1 "Error" || true
	@echo "\x1B[0m\c"
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
endif
	@echo "\x1B[32m  + Compile:\x1B[0m $@"

$(ODIR)%.o: $(SDIR)%.c
	@$(CC) $^ $(CFLAGS) -c -o $@ $(INCLUDE)
	@echo "\r\x1B[32m  + Compile:\x1B[0m $(notdir $^)"

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
	@echo "\x1B[31m  - Remove:\x1B[0m objects"

fclean: clean
	@make -C ./libft delete
	@rm -f $(EXEC)
	@echo "\x1B[31m  - Remove:\x1B[0m $(EXEC)"

re: fclean all

run: all
	@./$(EXEC) Mandelbrot

cleanlib:
	@make -C ./libft fclean


.PHONY: all clean fclean re run directories cleanlib

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itsalex <itsalex@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2018/09/04 16:17:20 by itsalex          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = wolf3d

export DEBUG = no
CC = clang
OS := $(shell uname -s)
MAKEFLAGS += --silent

ifeq ($(DEBUG), yes)
	CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g -ggdb
else
	CFLAGS = -Wall -Werror -Wextra -O3
endif

LIBFT_PATH = ./libft
LIBFT_FILE = $(LIBFT_PATH)/libft.a
LIBFT_DEP = $(LIBFT_PATH)/srcs/* $(LIBFT_PATH)/incs/*

MINILIBX_PATH = ./minilibx
MINILIBX_FILE = $(MINILIBX_PATH)/libmlx.a
MINILIBX_DEP = $(MINILIBX_PATH)/*.c $(MINILIBX_PATH)/*.h

# Link lib : "-L FOLDER -lXXX" where XXX = libXXX.a

ifeq ($(OS), Linux)
	LFLAGS = -L./libft -lft -L./minilibx -lmlx -lX11 -lXext -DLinux -lm
	INCLUDE = -I./incs -I/usr/include/mlx -I./minilibx
else
	LFLAGS = -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit
	INCLUDE = -I./incs -I./minilibx
endif

OUT_DIR = objs
SRC_DIR = srcs
INC_DIR = incs

SDIR =		./srcs/
SRCS =		$(notdir $(shell ls $(SRC_DIR)/*.c))
SRCC =		$(addprefix $(SDIR),$(SRCS))

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

all: directories $(EXEC)

$(LIBFT_FILE): $(LIBFT_DEP)
ifeq ($(OS), Linux)
	@echo -e "\x1B[34mLibft:\x1B[0m\n"
	@make -C ./libft
else
	@echo "\x1B[34mLibft:\x1B[0m\n"
	@make -C ./libft
endif

$(MINILIBX_FILE): $(MINILIBX_DEP)
ifeq ($(OS), Linux)
	@echo -e "\x1B[34mMinilibx:\x1B[0m\n"
	@make -C ./minilibx
else
	@echo "\x1B[34mMinilibx:\x1B[0m\n"
	@make -C ./minilibx
endif

$(EXEC): $(OBCC) $(LIBFT_FILE) $(MINILIBX_FILE)
ifeq ($(OS), Linux)
	@echo -e "\x1B[34m$(EXEC):\x1B[0m"
	$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo -e "\x1b[36m  + Compile program:\x1B[0m $@"
else
	@echo "\x1B[34m$(EXEC):\x1B[0m"
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo "\x1b[36m  + Compile program:\x1B[0m $@"
	@echo "\x1B[31m\c"
	@norminette srcs/* incs/* | grep -B 1 "Error" || true
	@echo "\x1B[0m\c"
endif

$(ODIR)%.o: $(SDIR)%.c
	@$(CC) $^ $(CFLAGS) -c -o $@ $(INCLUDE)
ifeq ($(OS), Linux)
	@echo -e "\r\x1B[32m  + Compile:\x1B[0m $(notdir $^)"
else
	@echo "\r\x1B[32m  + Compile:\x1B[0m $(notdir $^)"
endif

directories: ${OUT_DIR} ${SRC_DIR} ${INC_DIR}

${OUT_DIR}:
	@mkdir -p ${OUT_DIR}

${SRC_DIR}:
	@mkdir -p ${SRC_DIR}

${INC_DIR}:
	@mkdir -p ${INC_DIR}

clean:
	@make -C ./libft clean
	@rm -rf $(OUT_DIR)
ifeq ($(OS), Linux)
	@echo -e "\x1B[31m  - Remove:\x1B[0m objs"
else
	@echo "\x1B[31m  - Remove:\x1B[0m objs"
endif

fclean: clean
	@make -C ./libft delete
	@make -C ./minilibx clean
	@rm -f $(EXEC)
ifeq ($(OS), Linux)
	@echo -e "\x1B[31m  - Remove:\x1B[0m $(EXEC)"
else
	@echo "\x1B[31m  - Remove:\x1B[0m $(EXEC)"
endif

re: fclean
	make

run: all
	@./$(EXEC) maps/base

cleanlib:
	@make -C ./libft fclean


.PHONY: all clean fclean re run directories cleanlib

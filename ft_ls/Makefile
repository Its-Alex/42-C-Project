# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2017/01/16 23:35:56 by skyzie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_ls

export DEBUG = no
CC = clang
OS := $(shell uname -s)
MAKEFLAGS += --silent

ifeq ($(DEBUG), yes)
	CFLAGS = -Wall -Werror -Wextra -g -ggdb -fsanitize=address -v
else
	CFLAGS = -Wall -Werror -Wextra
endif

# Link lib : "-L FOLDER -lXXX" where XXX = libXXX.a

ifeq ($(OS), Linux)
	LFLAGS = -L./libft -lft
else
	LFLAGS = -L./libft -lft
endif

OUT_DIR = objs
SRC_DIR = srcs
INC_DIR = incs

SDIR =		./srcs/
SRCS =		$(shell ls $(SRC_DIR))
SRCC =		$(addprefix $(SDIR),$(SRCS))

INCLUDE = -I $(INC_DIR)

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

all: directories $(EXEC)

$(EXEC): $(OBCC)
ifeq ($(OS), Linux)
	@echo -e "\x1B[36mLibft:\x1B[0m\n"
	@make -C ./libft
	@echo -e "\x1B[36m$(EXEC):\x1B[0m"
	@clang $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
else
	@echo -e "\x1B[36mLibft:\x1B[0m\n"
	@make -C ./libft
	@echo -e "\x1B[36m$(EXEC):\x1B[0m"
	@echo -e "\x1B[31m\c"
	@norminette sources/* includes/* | grep -B 1 "Error" || true
	@echo -e "\x1B[0m\c"
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS) -lpthread -D_REENTRANT
endif
	@echo -e "\x1b[34m  + Compile program:\x1B[0m $@"

$(ODIR)%.o: $(SDIR)%.c
	@$(CC) $^ $(CFLAGS) -c -o $@ $(INCLUDE)
	@echo -e "\r\x1B[32m  + Compile:\x1B[0m $(notdir $^)"

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
	@echo -e "\x1B[31m  - Remove:\x1B[0m objs"

fclean: clean
	@make -C ./libft delete
	@rm -f $(EXEC)
	@echo -e "\x1B[31m  - Remove:\x1B[0m $(EXEC)"

re: fclean all

run: all
	@./$(EXEC) Mandelbrot

cleanlib:
	@make -C ./libft fclean


.PHONY: all clean fclean re run directories cleanlib

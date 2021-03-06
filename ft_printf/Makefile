# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2016/12/15 14:10:23 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = printftest
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
	LFLAGS = libft/libft.a 
else
	LFLAGS = libft/libft.a
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

all: directories $(EXEC)

$(EXEC): $(OBCC)
ifeq ($(OS), Linux)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo "Build $(EXEC) ✅"
else
	@make -C ./libft
	@echo "\x1B[31m\c"
	@norminette sources/* includes/* | grep -B 1 "Error" || true
	@echo "\x1B[0m\c"
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS) -lpthread -D_REENTRANT
	@echo "Build $(EXEC) ✅"
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
	@rm -f $(EXEC)
	@echo "Deleting $(EXEC) ✅"

re: fclean all

run: all
	@./$(EXEC)

cleanlib:
	@make -C ./libft fclean


.PHONY: all clean fclean re run directories cleanlib

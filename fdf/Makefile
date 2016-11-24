# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by alex              #+#    #+#              #
#    Updated: 2016/11/24 16:52:52 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
DEBUG = no
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = libft/libft.a mlx/libmlx.a -lmlx -framework OpenGL -framework AppKit
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

INCLUDE = -I incs/

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

all: directories $(NAME)

$(NAME): $(OBCC)
	@make -C ./libft
	@make -C ./mlx
	@echo "\x1B[31m\c"
	@norminette srcs/* incs/* | grep -B 1 "Error" || true
	@echo "\x1B[0m\c"
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo "Build $(NAME) ✅"

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

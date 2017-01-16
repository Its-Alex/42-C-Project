# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2017/01/16 15:30:56 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = libft.a

CC 				= clang
OS 				= $(shell uname -s)
MKDIR_P 		= mkdir -p
OUT_DIR 		= objets
SRC_DIR 		= sources
INC_DIR 		= includes
CFLAG 			= -Wall -Werror -Wextra

SDIR =				sources/
SRCS =				ft_atoi.c ft_isdigit.c ft_lstdelone.c \
					ft_memchr.c ft_putchar.c ft_putstr.c \
					ft_strcmp.c ft_striteri.c ft_strmapi.c \
					ft_strnstr.c ft_strtrim.c ft_bzero.c \
					ft_isprint.c ft_lstiter.c ft_memcmp.c \
					ft_putchar_fd.c ft_putstr_color.c \
					ft_strcpy.c ft_strjoin.c \
					ft_strncat.c ft_strrchr.c ft_swap.c \
					ft_freetab.c ft_itoa.c \
					ft_lstmap.c ft_memcpy.c ft_putendl.c \
					ft_putstr_fd.c ft_strdel.c \
					ft_strjoin_free.c ft_strncmp.c ft_strrev.c \
					ft_tolower.c ft_isalnum.c ft_itoa_base.c \
					ft_lstnew.c ft_memdel.c ft_putendl_fd.c \
					ft_strcat.c ft_strdup.c ft_strlcat.c \
					ft_strncpy.c ft_strsplit.c ft_toupper.c \
					ft_isalpha.c ft_lstadd.c ft_memalloc.c \
					ft_memmove.c ft_putnbr.c ft_strchr.c \
					ft_strequ.c ft_strlen.c ft_strnequ.c \
					ft_strstr.c ft_isascii.c ft_lstdel.c \
					ft_memccpy.c ft_memset.c ft_putnbr_fd.c \
					ft_strclr.c ft_striter.c ft_strmap.c \
					ft_strnew.c ft_strsub.c \
					ft_get_next_line.c ft_error.c \

SRCC =				$(addprefix $(SDIR),$(SRCS))

INCDIR = 			includes/

ODIR =				objets/
OBJS =				$(SRCS:.c=.o)
OBCC =				$(addprefix $(ODIR),$(OBJS))

all: directories $(EXEC)

$(EXEC): $(OBCC)
ifeq ($(OS), Linux)
	@ar rc libft.a $(OBCC)
	@ranlib $@
else
	@echo "\x1B[31m\c"
	@norminette sources/* includes/* | grep -B 1 "Error" || true
	@echo "\x1B[0m\c"
	@ar rc libft.a $(OBCC)
	@ranlib $@
endif
	@echo "\x1B[32m  + Compile:\x1B[0m $@"

$(ODIR)%.o: $(SDIR)%.c
	@$(CC) $^ $(CFLAG) -c -o $@ -I $(INCDIR)
	@echo "\r\033[1A\033[K\x1B[32m  + Compile:\x1B[0m $(notdir $^)"

directories: $(OUT_DIR) $(SRC_DIR) $(INC_DIR)

$(OUT_DIR):
	@$(MKDIR_P) $(OUT_DIR)

$(SRC_DIR):
	@$(MKDIR_P) $(SRC_DIR)

$(INC_DIR):
	@$(MKDIR_P) $(INC_DIR)

clean:
	@echo "\x1B[31m  - Remove:\x1B[0m libft/objects"
	@rm -rf objets

fclean: clean
	@echo "\x1B[31m  - Remove:\x1B[0m $(EXEC)"
	@rm -f $(EXEC)

delete:
	@echo "\x1B[31m  - Remove:\x1B[0m $(EXEC)"
	@rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re run directories cleanlib delete

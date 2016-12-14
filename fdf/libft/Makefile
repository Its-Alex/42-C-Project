# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2016/12/14 14:43:14 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC 				= clang
OS 				= $(shell uname -s)
MKDIR_P 		= mkdir -p
OUT_DIR 		= objets
SRC_DIR 		= sources
INC_DIR 		= includes
OUT_LIBC_DIR 	= objets/libc
CFLAG 			= -Wall -Werror -Wextra

SDIR =				sources/
SRCS =				libc/ft_atoi.c libc/ft_isdigit.c libc/ft_lstdelone.c \
					libc/ft_memchr.c libc/ft_putchar.c libc/ft_putstr.c \
					libc/ft_strcmp.c libc/ft_striteri.c libc/ft_strmapi.c \
					libc/ft_strnstr.c libc/ft_strtrim.c libc/ft_bzero.c \
					libc/ft_isprint.c libc/ft_lstiter.c libc/ft_memcmp.c \
					libc/ft_putchar_fd.c libc/ft_putstr_color.c \
					libc/ft_strcpy.c libc/ft_strjoin.c \
					libc/ft_strncat.c libc/ft_strrchr.c libc/ft_swap.c \
					libc/ft_freetab.c libc/ft_itoa.c \
					libc/ft_lstmap.c libc/ft_memcpy.c libc/ft_putendl.c \
					libc/ft_putstr_fd.c libc/ft_strdel.c \
					libc/ft_strjoin_free.c libc/ft_strncmp.c libc/ft_strrev.c \
					libc/ft_tolower.c libc/ft_isalnum.c libc/ft_itoa_base.c \
					libc/ft_lstnew.c libc/ft_memdel.c libc/ft_putendl_fd.c \
					libc/ft_strcat.c libc/ft_strdup.c libc/ft_strlcat.c \
					libc/ft_strncpy.c libc/ft_strsplit.c libc/ft_toupper.c \
					libc/ft_isalpha.c libc/ft_lstadd.c libc/ft_memalloc.c \
					libc/ft_memmove.c libc/ft_putnbr.c libc/ft_strchr.c \
					libc/ft_strequ.c libc/ft_strlen.c libc/ft_strnequ.c \
					libc/ft_strstr.c libc/ft_isascii.c libc/ft_lstdel.c \
					libc/ft_memccpy.c libc/ft_memset.c libc/ft_putnbr_fd.c \
					libc/ft_strclr.c libc/ft_striter.c libc/ft_strmap.c \
					libc/ft_strnew.c libc/ft_strsub.c \
					libc/get_next_line.c libc/ft_strjoin_free_endl.c \
					libc/parse_array_3d.c libc/putarray_3d.c libc/error.c\
					
SRCC =				$(addprefix $(SDIR),$(SRCS))

INCDIR = 			includes/

ODIR =				objets/
ODIR_LIBC =			objets/libc
OBJS =				$(SRCS:.c=.o)
OBCC =				$(addprefix $(ODIR),$(OBJS))


all: directories $(NAME)

$(NAME): $(OBCC)
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
	@echo "Build $(NAME) ✅"

$(ODIR)%.o: $(SDIR)%.c
	@$(CC) $^ $(CFLAG) -c -o $@ -I $(INCDIR)

directories: $(OUT_DIR) $(SRC_DIR) $(INC_DIR) $(OUT_LIBC_DIR)

$(OUT_DIR):
	@$(MKDIR_P) $(OUT_DIR)

$(ODIR_LIBC):
	@$(MKDIR_P) $(ODIR_LIBC)

$(SRC_DIR):
	@$(MKDIR_P) $(SRC_DIR)

$(INC_DIR):
	@$(MKDIR_P) $(INC_DIR)

clean:
	@echo "Deleting compilation files libft ✅"
	@rm -rf objets

fclean: clean
	@echo "Deleting $(NAME) ✅"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run directories cleanlib

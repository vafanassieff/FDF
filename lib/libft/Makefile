# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 15:00:14 by vafanass          #+#    #+#              #
#*   Updated: 2016/12/21 00:13:39 by vafanass         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./srcs
SRC_NAME = ft_bzero.c \
		   ft_isascii.c \
		   ft_memset.c \
		   ft_strlen.c \
		   ft_toupper.c \
		   ft_isalnum.c \
		   ft_isdigit.c \
		   ft_strcpy.c \
		   ft_strncpy.c \
		   ft_isalpha.c \
		   ft_isprint.c \
		   ft_tolower.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_memccpy.c \
		   ft_strcat.c \
		   ft_strncat.c \
		   ft_strlcat.c \
		   ft_strchr.c \
		   ft_strrchr.c \
		   ft_strcmp.c \
		   ft_strncmp.c \
		   ft_strstr.c \
		   ft_strnstr.c \
		   ft_atoi.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_putchar.c \
		   ft_putstr.c \
		   ft_putendl.c \
		   ft_putnbr.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_putnbr_fd.c \
		   ft_strdup.c \
		   ft_memalloc.c \
		   ft_memdel.c \
		   ft_strnew.c \
		   ft_strclr.c \
		   ft_strdel.c \
		   ft_strequ.c \
		   ft_strnequ.c \
		   ft_itoa.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strmap.c \
		   ft_strsub.c \
		   ft_strjoin.c \
		   ft_strtrim.c \
		   ft_strmapi.c \
		   ft_strsplit.c \
		   ft_lstnew.c \
		   ft_lstdelone.c \
		   ft_lstdel.c \
		   ft_lstadd.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_power.c \
		   ft_swap.c \
		   ft_recursive_factorial.c \
		   ft_foreach.c \
		   ft_sqrt.c \
		   ft_abs.c \
		   ft_islower.c \
		   ft_isupper.c \
		   ft_isspace.c \
		   ft_strrev.c \
		   get_next_line.c

CC = gcc
CFLAGS = -Werror -Wall -Wextra -Iincludes -c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ_PATH = ./
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
AR = ar rc
RLIB = ranlib
RM = rm -f
RMO = rm -f obj



all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) $(SRC)
		@$(AR) $(NAME) $(OBJ)
		@$(RLIB) $(NAME)
		@echo "\033[1;31m Libft Done \033[0m"


clean:
	    @$(RM) $(OBJ)

fclean: clean
	    @$(RM)  $(NAME)

re: fclean all

.PHONY: all, clean

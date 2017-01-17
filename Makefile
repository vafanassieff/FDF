#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 17:44:48 by vafanass          #+#    #+#              #
#*   Updated: 2016/12/21 00:43:39 by vafanass         ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

NAME = fdf
HEADER = fdf.h
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC_NAME = main.c \
	   parse_file.c \
	   utility.c \
	   util_parsing.c \
	   display.c \
	   key_event.c \
	   util_display.c

SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(SRC_NAME:.c=.o)
INCLUDE = -Iinclude -I lib/libft/includes -I lib//minilibx_el_capitan
LINCLUDE = -I lib/libft/includes -L lib/libft/ -lft -I lib/minilibx_el_capitan \
	-g -L lib/minilibx_el_capitan  -l mlx -framework OpenGL -framework AppKit

MAKELIB= make -C lib/libft/ && make -s -C lib/minilibx_el_capitan
CLEANLIB= make fclean -C lib/libft/ && make clean -C lib/minilibx_el_capitan

all: $(NAME)

$(NAME):
	@$(CLEANLIB)
	@$(MAKELIB)
	@$(CC) -c $(CFLAG) $(INCLUDE) $(SRC) 
	@$(CC) $(CFLAG) -o $(NAME) $(LINCLUDE) $(OBJS)

clean:
	@$(CLEANLIB)
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@$(CLEANLIB)

re: fclean all

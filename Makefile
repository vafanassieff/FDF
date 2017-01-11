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
SRCS = main.c \
	   parse_file.c \
	   utility.c \
	   util_parsing.c
OBJS = $(SRCS:.c=.o)
INCLUDE = -I libft/includes -I ./minilibx_el_capitan
LINCLUDE = -I libft/includes -L libft/ -lft -I ./minilibx_el_capitan \
	-g -L ./minilibx_el_capitan  -l mlx -framework OpenGL -framework AppKit

MAKELIB= make -C libft/ && make -s -C minilibx_el_capitan
CLEANLIB= make fclean -C libft/ && make clean -C minilibx_el_capitan

all: $(NAME)

$(NAME):
	@$(CLEANLIB)
	@$(MAKELIB)
	@$(CC) -c $(CFLAG) -I fdf.h $(INCLUDE) $(SRCS) 
	@$(CC) $(CFLAG) -o $(NAME) $(LINCLUDE) $(OBJS)

clean:
	@$(CLEANLIB)
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@$(CLEANLIB)

re: fclean all

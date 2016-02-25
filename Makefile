#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/18 17:13:57 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/25 16:07:31 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc -Wall -Wextra -Werror

CC_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/test.c

LIB_DRAW_SRC = lib_draw/draw_line.c

LIB_DRAW_BIN = $(LIB_DRAW_SRC:.c=.o)

BIN = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@$(CC) $(CC_FLAGS) $(SRC) $(LIB_DRAW_SRC) -o $(NAME) -I./includes -L./libft/ -lft

clean:
	@make -C libft/ clean
	@rm -rf $(BIN)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all

push:
	@git add .
	@git commit -m "Makefile pushed"
	@git push
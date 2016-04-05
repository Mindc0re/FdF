#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/18 17:13:57 by sgaudin           #+#    #+#              #
#    Updated: 2016/04/05 11:32:14 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc #-Wall -Wextra -Werror

LIB_D = lib_draw/

CC_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/parser.c src/init_fct.c src/free_fct.c src/key_hooks.c src/main.c \
	src/check_arg.c src/help.c

LIB_DRAW_SRC = $(LIB_D)draw_line.c $(LIB_D)perspective3d.c \
	$(LIB_D)math_fct.c $(LIB_D)draw_map.c $(LIB_D)rotation.c

LIB_DRAW_BIN = $(LIB_DRAW_SRC:.c=.o)

BIN = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/
	@printf "\033[31mCompilation des sources du FdF \033[0m"
	@$(CC) $(CC_FLAGS) $(SRC) $(LIB_DRAW_SRC) -o $(NAME) -I./includes -L./libft/ -lft
	@printf "\033[32mDone !\033[0m\n"

clean:
	@printf "\033[31mSuppression des fichiers .o libft \033[0m"
	@make -C libft/ clean
	@printf "\033[32mDone !\033[0m\n"
	@rm -rf $(BIN)

fclean: clean
	@make -C libft/ fclean
	@printf "\033[34mSuppression de l'executable FdF\033[0m\n"
	@rm -rf $(NAME)

re: fclean all

push:
	@git add .
	@git commit -m "Makefile pushed"
	@git push
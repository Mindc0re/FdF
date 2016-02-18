#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/18 17:13:57 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/18 18:31:56 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc -Wall -Wextra -Werror

CC_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/test.c

BIN = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) $(SRC) -o $(NAME) -I./includes

clean:
	rm -rf $(BIN)

fclean: clean
	rm -rf $(NAME)

re: fclean all

push:
	@git add .
	@git commit -m "Makefile pushed"
	@git push
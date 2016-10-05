# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfredric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/03 09:12:37 by cfredric          #+#    #+#              #
#    Updated: 2016/10/04 20:06:54 by cfredric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE  = fillit.c read.c

HEADER = fillit.h

OBJS = 	$(SOURCE:.c=.o)

CC = gcc

MEMERROR = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


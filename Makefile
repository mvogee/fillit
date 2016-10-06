# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfredric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/03 09:12:37 by cfredric          #+#    #+#              #
#    Updated: 2016/10/05 15:27:43 by mvogee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE  = main.c \
		  readv2.c \
		  libft/ft_strcpy.c \
		  libft/ft_strcat.c \
		  libft/ft_strlen.c \

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


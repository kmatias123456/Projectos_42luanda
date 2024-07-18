# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatias <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 03:20:27 by kmatias           #+#    #+#              #
#    Updated: 2024/05/28 03:42:30 by kmatias          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Automatizacao de processo de compilacao.
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./
SRC = ft_printc.c  \
	ft_printf.c \
	ft_putstr.c \
	ft_strchr.c \
	ft_hexadecimal.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_strlen.c \
	ft_printp.c \
	ft_unsigned.c \

#todos arquivos .c, cria uma exemplar para executaveis .o.
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)
re:	fclean all

.PHONY: all clean fclean

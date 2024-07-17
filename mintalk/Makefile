# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiangebeni <kiangebeni@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 12:55:27 by kiangebeni        #+#    #+#              #
#    Updated: 2024/07/07 17:34:56 by kiangebeni       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Arquivos de código-fonte
SRCS = server.c client.c

# Arquivos objeto gerados a partir dos códigos-fonte
OBJS := $(SRCS:%.c=%.o)

# Nome do executável principal do programa
NAME = minitalk

# Compilador recomendado
CC = gcc

# Flags de compilação do gcc
CFLAGS = -Wall -Wextra -Werror

# Comando para remover arquivos
RM = rm -f

# Regra padrão para compilação do projeto
all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -Ilibft -c $< -o $@

# Regras para compilação do executável
${NAME}: server client

server: server.o
	@make -C libft
	${CC} ${CFLAGS} $< -Llibft -lft -o $@

client: client.o
	@make -C libft
	${CC} ${CFLAGS} $< -Llibft -lft -o $@

# Compilação à parte da libft
libft:
	make -C libft

# Limpeza
clean:
	make -C libft clean
	${RM} ${OBJS}

fclean: clean
	${RM} server client

re: fclean all

.PHONY: all libft clean fclean re
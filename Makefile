# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 03:50:13 by kaheinz           #+#    #+#              #
#    Updated: 2022/05/29 15:10:59 by kaheinz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server

HEADER = minitalk.h

SRCS_SERVER = server.c\

LIBFT = libft/libft.a

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_OBJS = $(SRCS_SERVER:.c=.o)

$(SERVER_NAME): $(SRC_OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SRC_OBJS) $(LIBFT)

all:	$(SERVER_NAME)

clean:
	$(RM) $(SRC_OBJS)
	make clean -C libft/

fclean: clean
		$(RM) $(SERVER_NAME)
		make fclean -C libft/

re:	fclean all

.PHONY: all clean fclean re

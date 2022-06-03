# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 03:50:13 by kaheinz           #+#    #+#              #
#    Updated: 2022/06/04 01:22:03 by kaheinz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server

CLIENT_NAME = client

HEADER = minitalk.h

SRCS_SERVER = server.c\

SRCS_CLIENT = client.c\

LIBFT = libft/libft.a

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SERVER_OBJS = $(SRCS_SERVER:.c=.o)
CLIENT_OBJS = $(SRCS_CLIENT:.c=.o)

$(SERVER_NAME): $(SERVER_OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(LIBFT)

$(CLIENT_NAME): $(CLIENT_OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LIBFT)

all:	$(SERVER_NAME) $(CLIENT_NAME)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	make clean -C libft/

fclean: clean
		$(RM) $(SERVER_NAME) $(CLIENT_NAME)
		make fclean -C libft/

re:	fclean all

.PHONY: all clean fclean re

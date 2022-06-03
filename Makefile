# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 03:50:13 by kaheinz           #+#    #+#              #
#    Updated: 2022/06/03 23:15:33 by kaheinz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server

CLIENT_NAME = client

CLIENT2_NAME = client2

HEADER = minitalk.h

SRCS_SERVER = server.c\

SRCS_CLIENT = client.c\

SRCS_CLIENT2 = client2.c\

LIBFT = libft/libft.a

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SERVER_OBJS = $(SRCS_SERVER:.c=.o)
CLIENT_OBJS = $(SRCS_CLIENT:.c=.o)
CLIENT2_OBJS = $(SRCS_CLIENT2:.c=.o)

$(SERVER_NAME): $(SERVER_OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(LIBFT)

$(CLIENT_NAME): $(CLIENT_OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LIBFT)

$(CLIENT2_NAME): $(CLIENT2_OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(CLIENT2_NAME) $(CLIENT2_OBJS) $(LIBFT)

all:	$(SERVER_NAME) $(CLIENT_NAME) $(CLIENT2_NAME)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(CLIENT2_OBJS)
	make clean -C libft/

fclean: clean
		$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(CLIENT2_NAME)
		make fclean -C libft/

re:	fclean all

.PHONY: all clean fclean re

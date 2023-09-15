# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 05:20:05 by tfiguero          #+#    #+#              #
#    Updated: 2023/09/15 06:34:24 by tfiguero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERV = server
NAME_CLI = client

SRC_CLI = client.c
SRC_SERV = server.c


OBJS_CLI	= 	$(SRC_CLI:.c=.o)
OBJS_SERV	=	$(SRC_SERV:.c=.o)

CC	= 	cc
RM	= 	rm -f
FLAGS	= 	-Wall -Wextra -Werror

all: ${OBJS_CLI} ${OBJS_SERV}
			$(CC) $(FLAGS) $(OBJS_CLI) -o ${NAME_CLI}
			$(CC) $(FLAGS) $(OBJS_SERV) -o ${NAME_SERV}
			@echo "Hello, $(NAME_SERV) and $(NAME_CLI) already compiled 🌚"
	
client: ${OBJS_CLI}
			$(CC) $(FLAGS) $(OBJS_CLI) -o ${NAME_CLI}
			@echo "Hello, $(NAME_CLI) already compiled 🌚"

server: ${OBJS_SERV}
			$(CC) $(FLAGS) $(OBJS_SERV) -o ${NAME_SERV}
			@echo "Hello, $(NAME_SERV) already compiled 🌚"

fclean: clean
	$(RM) $(NAME_CLI) $(NAME_SERV) 

clean:
	$(RM) $(OBJS_CLI) $(OBJS_SERV) 

re: fclean all

.PHONY: all client server clean fclean re
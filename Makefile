# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaengha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 21:07:06 by psaengha          #+#    #+#              #
#    Updated: 2023/07/06 16:50:46 by psaengha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SVR = server.c
SVR_NAME = server
UTILS = ft_printf/ft_printf.c \
		ft_printf/c.c \
		ft_printf/di.c \
		ft_printf/p.c \
		ft_printf/s.c \
		ft_printf/u.c \
		ft_printf/x.c \
		ft_printf/xupper.c
CLIENT = client.c
CLIENT_NAME = client

INCS_DIR = ./includes
IFLAGS = -I $(INCS_DIR)

all: $(NAME)

$(NAME): server client

server:
	gcc -Wall -Wextra -Werror $(UTILS) $(SVR) $(IFLAGS) -o $(SVR_NAME)

client:
	gcc -Wall -Wextra -Werror $(UTILS) $(CLIENT) -o $(CLIENT_NAME)

clean:
	rm -rf $(SVR_NAME)
	rm -rf $(CLIENT_NAME)

fclean: clean

re: fclean client server

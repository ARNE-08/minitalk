# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaengha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 21:07:06 by psaengha          #+#    #+#              #
#    Updated: 2023/07/05 17:48:17 by psaengha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

INCS_DIR = ./includes
IFLAGS = -I $(INCS_DIR)

server:
	gcc -Wall -Wextra -Werror $(UTILS) $(SVR) $(IFLAGS) -o $(SVR_NAME)

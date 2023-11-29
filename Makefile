# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 14:30:32 by cbaroi            #+#    #+#              #
#    Updated: 2023/11/29 14:48:53 by cbaroi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/cnvt_big.c srcs/cnvt_small.c srcs/ft_printf.c srcs/pf_addr.c srcs/pf_flags.c srcs/pf_putchar.c srcs/pf_putnbr.c srcs/pf_putstr.c
OBJS = ${SRCS: .c=.o}
HEADER = ft_printf.h

all: ${NAME}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

%.o: %.c ${HEADER}
		cc -Wall -Wextra -Werror -c $< -o $@

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus

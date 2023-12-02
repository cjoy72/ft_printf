# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 12:41:07 by cbaroi            #+#    #+#              #
#    Updated: 2023/12/03 00:11:09 by cbaroi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MANDATORY_SRCS = srcs/ft_printf.c srcs/pf_addr.c srcs/pf_cnvt.c srcs/pf_flags.c srcs/pf_putchar.c srcs/pf_putnbr.c srcs/pf_putstr.c
MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
HEADER = ft_printf.h

all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	ar rc ${NAME} ${MANDATORY_OBJS}

%.o: %.c ${HEADER}
	cc -Wall -Wextra -Werror -c $?

clean:
	rm -f ${MANDATORY_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 12:41:07 by cbaroi            #+#    #+#              #
#    Updated: 2023/12/01 12:43:19 by cbaroi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MANDATORY_SRCS = ft_printf.c pf_cnvts.c pf_addr.c pf_putchar.c pf_putstr.c pf_cnvtb.c pf_putnbr.c pf_flags.c
MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
HEADER = ft_printf.h

all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	ar rc ${NAME} ${MANDATORY_OBJS}
	ranlib ${NAME}

%.o: %.c ${HEADER}
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f ${MANDATORY_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

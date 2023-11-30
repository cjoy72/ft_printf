/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:11:15 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/30 16:51:06 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	pf_putchar(int c);
int	pf_putstr(const char *str);
int	cnvt_small(unsigned long number, short base);
int	cnvt_big(unsigned long number, short base);
int	pf_addr(char *ptr);
int	pf_putnbr_unsigned(unsigned int number);
int	pf_putnbr(int nbr);
int	pf_flags(va_list args, char *str);
int	ft_printf(const char *str, ...);

#endif

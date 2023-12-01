/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:45:51 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/01 12:36:27 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flags(va_list args, char *str, size_t *count)
{
	if (*str == 'c')
		pf_putchar(va_arg(args, int), count);
	else if (*str == 's')
		pf_putstr(va_arg(args, char *), count);
	else if (*str == 'p')
		pf_addr(va_arg(args, void *), count);
	else if (*str == 'i' || *str == 'd')
		pf_putnbr(va_arg(args, int), count);
	else if (*str == 'u')
		pf_cnvts(va_arg(args, unsigned int), 10, count);
	else if (*str == 'x')
		pf_cnvts(va_arg(args, unsigned int), 16, count);
	else if (*str == 'X')
		pf_cnvtb(va_arg(args, unsigned int), 16, count);
	else if (*str == '%')
		pf_putchar('%', count);
}

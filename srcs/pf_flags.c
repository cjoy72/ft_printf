/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:59:47 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/03 00:02:23 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
		pf_cnvt(va_arg(args, unsigned int), 10, 'x', count);
	else if (*str == 'x')
		pf_cnvt(va_arg(args, unsigned int), 16, 'x', count);
	else if (*str == 'X')
		pf_cnvt(va_arg(args, unsigned int), 16, 'X', count);
}

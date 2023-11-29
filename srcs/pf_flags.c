/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:26:36 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/29 14:28:10 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_flags(va_list args, char *str)
{
	int	count;

	if (*str == 'c')
		count = pf_putchar(va_arg(args, int));
	else if (*str == 's')
		count = pf_putstr(va_arg(args, char *));
	else if (*str == 'p')
		count = pf_addr(va_arg(args, void *));
	else if (*str == 'i' || *str == 'd')
		count = pf_putnbr(va_arg(args, int));
	else if (*str == 'u')
		count = cnvt_small(va_arg(args, unsigned int), 10);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			count = cnvt_small(va_arg(args, unsigned int), 16);
		else
			count = cnvt_big(va_arg(args, unsigned int), 16);
	}
	else if (*str == '%')
		count = pf_putchar('%');
	return (count);
}

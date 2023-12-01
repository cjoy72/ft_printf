/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:36:16 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/01 12:36:47 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	if (!str)
		return (count);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			pf_flags(args, (char *)(++str), &count);
		else
			pf_putchar(*(str++), &count);
	}
	va_end(args);
	return (count);
}

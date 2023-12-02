/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:00:07 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/03 00:01:47 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
		{
			pf_flags(args, (char *)(++str), &count);
			str++;
		}
		else
			pf_putchar(*(str++), &count);
	}
	va_end(args);
	return (count);
}

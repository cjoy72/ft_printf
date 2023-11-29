/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:03:44 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/29 14:28:51 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!str)
		return (count);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count += pf_flags(args, (char *)(++str));
		else
			count += pf_putchar(str++);
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	count;

	count = ft_printf("Hello World!");
	printf("\n%d\n", count);
	count = printf("Hello World!");
	printf("\n%d\n", count);
	return (0);
}
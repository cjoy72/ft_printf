/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:03:44 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/29 13:44:53 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	pf_putchar(const char *str)
{
	int	bytes_written;

	bytes_written = write(1, str, 1);
	if (bytes_written == 1)
		return (1);
	else
		return (0);
}

int	pf_putstr(const char *str)
{
	int	count;

	count = 0;
	while (*str)
		count += pf_putchar(str++);
	return (count);
}

int	cnvt_small(unsigned long number, short base)
{
	char	*symbol;
	int		count;

	symbol = "0123456789abcdef";
	count = 0;
	if (number >= (unsigned long)base)
	{
		count += cnvt_small(number / base, base);
		number = number % base;
	}
	count += pf_putchar(symbol[number]);
	return (count);
}

int	cnvt_big(unsigned long number, short base)
{
	char	*symbol;
	int		count;

	symbol = "0123456789abcdef";
	count = 0;
	if (number >= (unsigned long)base)
	{
		count += cnvt_big(number / base, base);
		number = number % base;
	}
	count += pf_putchar(symbol[number]);
	return (count);
}

int	pf_addr(char *ptr)
{
	unsigned long	ptr_addr;
	int				count;

	if (ptr == NULL)
		return (pf_putstr("(nil)"));
	ptr_addr = (unsigned long)ptr;
	count = pf_putstr("0x");
	count += cnvt_small(ptr_addr, 16);
	return (count);
}

int	pf_putnbr_unsigned(unsigned int number)
{
	int	count;

	count = 0;
	if (number >= 10)
	{
		count += pf_putnbr_unsigned(number / 10);
	}
	count += pf_putchar((number % 10) + '0');
	return (count);
}

int	pf_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += pf_putchar('-');
		count += pf_putnbr_unsigned((unsigned int)(-nbr));
	}
	else
		count += pf_putnbr_unsigned((unsigned int)nbr);
	return (count);
}

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

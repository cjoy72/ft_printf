/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnvt_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:23:07 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/29 14:27:52 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cnvt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:58:29 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/03 00:04:52 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_cnvt(unsigned long n, int base, char c, size_t *count)
{
	char	*symb_short;
	char	*symb_long;

	symb_short = "0123456789abcdef";
	symb_long = "0123456789ABCDEF";
	if (n >= (unsigned long)base)
	{
		pf_cnvt(n / base, base, c, count);
		n = n % base;
	}
	if (c == 'X')
		pf_putchar(symb_long[n], count);
	else
		pf_putchar(symb_short[n], count);
}

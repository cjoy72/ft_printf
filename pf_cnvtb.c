/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cnvtB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:25:35 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/01 12:33:49 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_cnvtb(long n, int base, size_t *count)
{
	char	*symbol;

	symbol = "0123456789ABCDEF";
	if (n < 0)
	{
		pf_putchar('-', count);
		pf_cnvtb(-n, base, count);
	}
	if (n >= base)
	{
		pf_cnvtb(n / base, base, count);
		n = n % base;
	}
	pf_putchar(symbol[n], count);
}

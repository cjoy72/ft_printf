/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cnvtS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:08:11 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/01 12:37:30 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_cnvts(long n, int base, size_t *count)
{
	char	*symbol;

	symbol = "0123456789abcdef";
	if (n < 0)
	{
		pf_putchar('-', count);
		pf_cnvts(-n, base, count);
	}
	if (n >= base)
	{
		pf_cnvts(n / base, base, count);
		n = n % base;
	}
	pf_putchar(symbol[n], count);
}

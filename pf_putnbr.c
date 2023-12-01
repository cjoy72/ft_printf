/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:16:12 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/01 12:20:16 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putnbr(int nbr, size_t *count)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		pf_putchar('-', count);
		n = -n;
	}
	while (n >= 10)
	{
		pf_putnbr(n / 10, count);
		n = n % 10;
	}
	pf_putchar((n + '0'), count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:59:25 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/03 00:01:09 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_putnbr(int nbr, size_t *count)
{
	if (nbr < 0)
	{
		pf_putchar('-', count);
		if (nbr == -2147483648)
		{
			pf_putstr("2147483648", count);
			return ;
		}
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		pf_putnbr(nbr / 10, count);
		nbr = nbr % 10;
	}
	pf_putchar((nbr + '0'), count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:25:43 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/29 14:28:23 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

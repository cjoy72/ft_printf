/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:21:36 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/29 14:28:31 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_putstr(const char *str)
{
	int	count;

	count = 0;
	while (*str)
		count += pf_putchar(str++);
	return (count);
}

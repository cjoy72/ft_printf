/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:24:06 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/29 14:28:04 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

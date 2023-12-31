/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:59:03 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/03 00:00:49 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_addr(void *ptr, size_t *count)
{
	unsigned long	ptr_addr;

	if (ptr == NULL)
		pf_putstr("(nil)", count);
	else
	{
		ptr_addr = (unsigned long)ptr;
		pf_putstr("0x", count);
		pf_cnvt(ptr_addr, 16, 'x', count);
	}
}

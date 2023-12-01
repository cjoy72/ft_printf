/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:04:28 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/01 12:07:46 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_addr(void *ptr, size_t *count)
{
	unsigned long	ptr_addr;

	if (ptr == NULL)
		pf_putstr("(nill)", count);
	else
	{
		ptr_addr = (unsigned long)ptr;
		pf_putstr("0x", count);
		pf_cnvts(ptr_addr, 16, count);
	}
}

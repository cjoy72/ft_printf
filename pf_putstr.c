/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:56:08 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/01 11:58:39 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *str, size_t *count)
{
	if (!str)
		*count += write(1, "(null)", 6);
	else
	{
		while (*str)
			pf_putchar(*(str++), count);
	}
}

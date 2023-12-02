/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:58:03 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/03 00:42:16 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_putstr(char *str, size_t *count)
{
	int	i;

	i = -1;
	if (!str)
		*count = write(1, "(null)", 6);
	else
	{
		while (str[++i])
		{
			pf_putchar(str[i], count);
		}
	}
}

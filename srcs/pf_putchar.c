/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:21:05 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/29 14:28:15 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_putchar(const char *str)
{
	int	bytes_written;

	bytes_written = write(1, str, 1);
	if (bytes_written == 1)
		return (1);
	else
		return (0);
}

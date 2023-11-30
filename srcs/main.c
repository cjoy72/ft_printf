/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:17 by cbaroi            #+#    #+#             */
/*   Updated: 2023/11/30 16:52:01 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello World!");
	printf("\n%d\n", count);
	count = printf("Hello World!");
	printf("\n%d\n", count);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:37:28 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/03 00:04:04 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
void	pf_flags(va_list args, char *str, size_t *count);
void	pf_putchar(char c, size_t *count);
void	pf_putstr(char *str, size_t *count);
void	pf_addr(void *ptr, size_t *count);
void	pf_cnvt(unsigned long n, int base, char c, size_t *count);
void	pf_putnbr(int nbr, size_t *count);

#endif

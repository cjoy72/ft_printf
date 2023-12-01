/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:37:28 by cbaroi            #+#    #+#             */
/*   Updated: 2023/12/01 12:39:50 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
void	pf_putchar(char c, size_t *count);
void	pf_putstr(char *str, size_t *count);
void	pf_cnvts(long n, int base, size_t *count);
void	pf_cnvtb(long n, int base, size_t *count);
void	pf_addr(void *ptr, size_t *count);
void	pf_flags(va_list args, char *str, size_t *count);
void	pf_putnbr(int nbr, size_t *count);

#endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//For testing purpose
#include <stdio.h>

int		ft_printf(char const *str, ...);
void	pf_flags(va_list args, char *str, size_t *count);
void	pf_putchar(char c, size_t *count);
void	pf_putstr(char *str, size_t *count);
void	pf_addr(void *ptr, size_t *count);
void	pf_cnvt(unsigned long n, int base, char c, size_t *count);
void	pf_putnbr(int nbr, size_t *count);

void	pf_putchar(char c, size_t *count)
{
	(*count) += write(1, &c, 1);
}

void	pf_putstr(char *str, size_t *count)
{
	int	i;

	i = -1;
	if (!str)
		*count = write(1, "(nill)", 6);
	else
	{
		while (str[++i])
		{
			pf_putchar(str[i], count);
		}
	}
}

void	pf_cnvt(unsigned long n, int base, char c, size_t *count)
{
	char	*symb_short;
	char	*symb_long;

	symb_short = "0123456789abcdef";
	symb_long = "0123456789ABCDEF";
	if (n >= (unsigned long)base)
	{
		pf_cnvt(n / base, base, c, count);
		n = n % base;
	}
	if (c == 'X')
		pf_putchar(symb_long[n], count);
	else
		pf_putchar(symb_short[n], count);
}

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

void	pf_putnbr(int nbr, size_t *count)
{
	if (nbr < 0)
	{
		pf_putchar('-', count);
		if (nbr == -2147483648)
		{
			pf_putstr("2147483648", count);
			return ;
		}
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		pf_putnbr(nbr / 10, count);
		nbr = nbr % 10;
	}
	pf_putchar((nbr + '0'), count);
}

void	pf_flags(va_list args, char *str, size_t *count)
{
	if (*str == 'c')
		pf_putchar(va_arg(args, int), count);
	else if (*str == 's')
		pf_putstr(va_arg(args, char *), count);
	else if (*str == 'p')
		pf_addr(va_arg(args, void *), count);
	else if (*str == 'i' || *str == 'd')
		pf_putnbr(va_arg(args, int), count);
	else if (*str == 'u')
		pf_cnvt(va_arg(args, unsigned int), 10, 'x', count);
	else if (*str == 'x')
		pf_cnvt(va_arg(args, unsigned int), 16, 'x', count);
	else if (*str == 'X')
		pf_cnvt(va_arg(args, unsigned int), 16, 'X', count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	if (!str)
		return (count);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			{
				pf_flags(args, (char *)(++str), &count);
				str++;
			}
		else
			pf_putchar(*(str++), &count);
	}
	va_end(args);
	return (count);
}

int	main()
{
	int	min;
	int		conta;

	min = -2147483648;
	conta = ft_printf("Hello World! %d", min);
	ft_printf("\nNumbers of Characters Written: %d\n", conta);
	conta = printf("Hello World! %d", min);
	printf("\nNumbers of Characters Written: %d\n", conta);
	return (0);
}

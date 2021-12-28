#include <unistd.h>
#include "ft_printf.h"

void	ft_convert_print_to_hex(unsigned long ch, int *res)
{
	char			ss[16] = "0123456789abcdef";
	char			addr[32];
	int i;
	addr[31] = '\0';
	i = 30;
	while (ch > 0)
	{
		addr[i] = ss[ch % 16];
		i--;
		ch = ch / 16;
	}
	addr[i] = 'x';
	i--;
	addr[i] = '0';
	write(1, &addr[i], 31-i);
	*res = *res + 31 - i;
}

static void	ft_define(char a, va_list arg, int *res)
{
	unsigned int	i;
	unsigned long	uns_l;

	if (a == 'c')
	{
		i = va_arg(arg, int);
		write(1, &i, 1);
		*res = *res + 1;
	}
	else if (a == 's')
		ft_putstr(va_arg(arg, char *), res);
	else if(a == 'p')
	{
		uns_l = va_arg(arg, unsigned long);
		if (uns_l != 0)
			ft_convert_print_to_hex(uns_l, res);
		else
		{
			write(1, "(nil)", 5);
			*res = *res + 5;
		}
	}
	else if (a == '%')
	{
		write(1, "%", 1);
		*res = *res + 1;
	}
	else if (a == 'i' || a == 'd')
		ft_putnbr_fd(va_arg(arg, int), 1, res);
}

int	ft_printf (const char *format, ...)
{
	va_list arg;
	int		res;
	res = 0;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			res++;
		}
		else
		{
			format++;
			ft_define(*format, arg, &res);
		}
		format++;
	}
	va_end(arg);
	return (res);
}

// int	main(void)
// {
// 	//int i = 1;
// 	printf(" %p %p \n", 0, 0);
// 	ft_printf(" %p %p ", 0, 0);
// }
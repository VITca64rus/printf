#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_create_string_hex(int flag)
{
	char	*s;
	char	a;
	int		i;
	s = malloc(16);
	a = '0';
	i = 0;
	while (a <= '9')
	{
		s[i] = a;
		a++;
		i++;
	}
	if (flag == 0)
		a = 'a';
	else
		a = 'A';
	while (((flag != 0) && (a <= 'F')) || ((flag == 0) && (a <= 'f')))
	{
		s[i] = a;
		i++;
		a++;
	}
	return (s);
}

void	ft_convert_print_to_hex(unsigned long long ch, int *res, int flag)
{
	char			*ss;
	char			addr[32];
	int i;
	addr[31] = '\0';
	i = 30;
	ss = ft_create_string_hex(flag);
	if (ch == 0)
	{
		write(1, "0", 1);
		*res = *res + 1;
	}
	while (ch > 0)
	{
		addr[i] = ss[ch % 16];
		i--;
		ch = ch / 16;
	}
	i++;
	write(1, &addr[i], 31 - i);
	*res = *res + 31 - i;
	free(ss);
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
		{
			write(1, "0x", 2);
			*res = *res + 2;
			ft_convert_print_to_hex(uns_l, res, 0);
		}
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
	else if (a == 'u')
		ft_putnbr_fd_no_znak(va_arg(arg, unsigned int), 1, res);
	else if (a == 'x')
		ft_convert_print_to_hex(va_arg(arg, unsigned int), res, 0);
	else if (a == 'X')
		ft_convert_print_to_hex(va_arg(arg, unsigned int), res, 1);
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
// 	printf("%d\n", printf(" %x ", -1));
// 	printf("%d", ft_printf(" %x ", -1));
// }
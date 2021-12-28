#include <unistd.h>
#include "ft_printf.h"

static void	ft_define(char a, va_list arg, int *res)
{
	unsigned int	i;

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
		
	}
	else if (a == '%')
	{
		write(1, "%", 1);
		*res = *res + 1;
	}
	else if (a == 'i')
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
// 	int i = 1;
// 	printf("%d\n", printf(" %p ", &i));
// 	printf("%d", ft_printf(" %p ", &i));
// }
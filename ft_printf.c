#include <stdarg.h>
#include <unistd.h>

static void	ft_putstr(char *s)
{
	while (*s != '\0')
	{
		write (1, s, 1);
		s++;
	}
}

static void	ft_define(char a, va_list arg)
{
	unsigned int	i;
	char			*s;

	if (a == 'c')
	{
		i = va_arg(arg, int);
		write (1, &i, 1);
	}
	else if (a == 's')
	{
		s = va_arg(arg, char *);
		ft_putstr(s);
	}
	else if (a == 'p')
	{

	}
}

int	ft_printf (const char *format, ...)
{
	va_list arg;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		else
		{
			format++;
			ft_define(*format, arg);
		}
		format++;
	}
	va_end(arg);
}

int	main(void)
{
	ft_printf("ananas %s programmer\0", "viktor");
}
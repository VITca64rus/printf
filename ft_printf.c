/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:11:03 by sazelda           #+#    #+#             */
/*   Updated: 2021/12/29 15:29:46 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void	ft_if_p(va_list arg, int *res)
{
	unsigned long	uns_l;

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
	else if (a == 'p')
	{
		ft_if_p(arg, res);
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

int	ft_printf(const char *format, ...)
{
	va_list	arg;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:10:51 by sazelda           #+#    #+#             */
/*   Updated: 2021/12/29 22:02:09 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdlib.h>

void	ft_putnbr_fd_no_znak(unsigned int n, int fd, int *res)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr_fd_no_znak(n / 10, fd, res);
		ft_putnbr_fd_no_znak(n % 10, fd, res);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
		*res = *res + 1;
	}
}

void	ft_putnbr_fd(int n, int fd, int *res)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*res = *res + 11;
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		*res = *res + 1;
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, res);
		ft_putnbr_fd(n % 10, fd, res);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
		*res = *res + 1;
	}
}

void	ft_putstr(char *s, int *res)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*res = *res + 6;
	}
	else
	{
		while (*s != '\0')
		{
			write (1, s, 1);
			s++;
			*res = *res + 1;
		}
	}
}

void	ft_create_string_hex(int flag, char *s)
{
	char	a;
	int		i;

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
}

void	ft_convert_print_to_hex(unsigned long long ch, int *res, int flag)
{
	char	*ss;
	char	addr[32];
	int		i;

	addr[31] = '\0';
	i = 30;
	ss = (char *)malloc(16);
	ft_create_string_hex(flag, ss);
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

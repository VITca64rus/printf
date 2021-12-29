/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:10:51 by sazelda           #+#    #+#             */
/*   Updated: 2021/12/29 14:20:27 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

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

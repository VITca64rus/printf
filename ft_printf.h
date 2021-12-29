/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:19:37 by sazelda           #+#    #+#             */
/*   Updated: 2021/12/29 14:19:43 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

void	ft_putnbr_fd(int n, int fd, int *res);
void	ft_putstr(char *s, int *res);
int		ft_printf(const char *format, ...);
void	ft_putnbr_fd_no_znak(unsigned int n, int fd, int *res);

#endif
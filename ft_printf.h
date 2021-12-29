/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:19:37 by sazelda           #+#    #+#             */
/*   Updated: 2021/12/29 22:02:13 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

void	ft_putnbr_fd(int n, int fd, int *res);
void	ft_putstr(char *s, int *res);
int		ft_printf(const char *format, ...);
void	ft_putnbr_fd_no_znak(unsigned int n, int fd, int *res);
void	ft_convert_print_to_hex(unsigned long long ch, int *res, int flag);
void	ft_create_string_hex(int flag, char *s);

#endif
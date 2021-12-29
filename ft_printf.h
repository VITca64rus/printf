#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

void	ft_putnbr_fd(int n, int fd, int *res);
void	ft_putstr(char *s, int *res);
int		ft_printf (const char *format, ...);
void	ft_putnbr_fd_no_znak(unsigned int n, int fd, int *res);

#endif
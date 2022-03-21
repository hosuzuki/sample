#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_lst
{
	va_list args;
	size_t len;
	int	status;
	int	sign;
	long long	wid;
	long long pre;
} t_lst;

int	ft_printf(const char *fmt, ...);
int	ft_isdigit(int	c);
size_t ft_strlen(char *str);
void ft_write_str(t_lst *lst, char *str);
void ft_write_char(t_lst *lst, int c);
void ft_deci(t_lst *lst, int d);
void ft_hex(t_lst *lst, unsigned int h);

#endif

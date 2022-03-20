#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_lst
{
	va_list args;
	size_t len;
	int	sign;
	long long	wid;
	long long pre;
} t_lst;

int	ft_printf(const char *fmt, ...);


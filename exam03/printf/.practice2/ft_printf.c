#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_lst
{
	va_list args;
	size_t len;
	int sign;
	int status;
	int pre_flag;
	long long pre;
	long long wid;
} t_lst;

int ft_isdigit(int c)
{
	return ('0' <= (char)c && (char)c <= '9');
}

size_t ft_strlen(char *s)
{
	size_t i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void ft_write_str(t_lst *lst, char *s)
{
	size_t total;

	total = lst->len + ft_strlen(s);
	if (INT_MAX < total)
	{
		lst->status = -1;
		return ;
	}
	lst->len += write(1, s, ft_strlen(s));
}

void ft_write_char(t_lst *lst, int c)
{
	size_t total;
	total = lst->len + 1;
	if (INT_MAX < total)
	{
		lst->status = -1;
		return ;
	}
	lst->len += write(1, &c, 1);
}

void ft_itoa(char *res, int d, int *i)
{
	if (d == INT_MIN)
	{
		ft_itoa(res, d / 10, i);
		res[(*i)++] = '8';
	}
	else if (d < 0)
		ft_itoa(res, -d, i);
	else if (9 < d)
	{
		ft_itoa(res, d / 10, i);
		ft_itoa(res, d % 10, i);
	}
	else
		res[(*i)++] = d + '0';
}

int ft_space(t_lst *lst, int i)
{
	int res = 0;
	if (lst->pre < i)
		res = lst->wid -i;
	else
		res = lst->wid - lst->pre;
	if (lst->sign == -1)
		res--;
	return (res);
}

int ft_zero(t_lst *lst, int i)
{
	if (lst->pre_flag == 1 && lst->pre > i)
		return (lst->pre - i);
	return (0);
}

void ft_itoh(char *base, char *res, unsigned int h, int *i)
{
	if (h >= 16)
		ft_itoh(base, res, h / 16, i);
	res[(*i)++] = base[h % 16];
}

void ft_hex(t_lst *lst, unsigned int h)
{
	char res[15] = {'\0'};
	int zero;
	int space;
	int i = 0;
	
	ft_itoh("0123456789abcdef", res, h, &i);
	if (lst->wid > lst->pre && lst->wid > i)
	{
		space = ft_space(lst, i);
		while (0 < space--)
			ft_write_char(lst, ' ');
	}
	if (i < lst->pre)
	{
		zero = ft_zero(lst, i);
		while (0 < zero--)
			ft_write_char(lst, '0');
	}
	if (h == 0 && lst->pre_flag == 1 && lst->pre == 0)
	{
		if (lst->wid > 0)
			ft_write_char(lst, ' ');
		return ;
	}
	ft_write_str(lst, res);
}
void ft_deci(t_lst *lst, int d)
{
	char res[15] = {'\0'};
	int zero;
	int space;
	int i = 0;
	
	ft_itoa(res, d, &i);
	if (d < 0)
		lst->sign = -1;
	if (lst->wid > lst->pre && lst->wid > i)
	{
		space = ft_space(lst, i);
		while (0 < space--)
			ft_write_char(lst, ' ');
	}
	if (d < 0)
		ft_write_char(lst, '-');
	if (i < lst->pre)
	{
		zero = ft_zero(lst, i);
		while (0 < zero--)
			ft_write_char(lst, '0');
	}
	if (d == 0 && lst->pre_flag == 1 && lst->pre == 0)
	{
		if (lst->wid > 0)
			ft_write_char(lst, ' ');
		return ;
	}
	ft_write_str(lst, res);
}


void ft_str(t_lst *lst, char *s)
{
	char null[7] = "(null)";
	int	len;
	int word;
	int space;
	int i = 0;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (lst->pre < len && lst->pre_flag == 1)
		word = 	lst->pre;
	else
		word = len;
	space = lst->wid - word;
	while (0 < space--)
		ft_write_char(lst, ' ');
	while (i < word)
	{
		if (!s)
			ft_write_char(lst, null[i++]);
		else
			ft_write_char(lst, s[i++]);
	}
}

void ft_speci(t_lst *lst, const char *fmt, size_t *i)
{
	if (fmt[*i] == 'd')
	{
		ft_deci(lst, va_arg(lst->args, int));
		(*i)++;
	}
	else if (fmt[*i] == 'x')
	{
		ft_hex(lst, va_arg(lst->args, unsigned int));
		(*i)++;
	}
	if (fmt[*i] == 's')
	{
		ft_str(lst, va_arg(lst->args, char *));
		(*i)++;
	}
}

void ft_flag(t_lst *lst, const char *fmt, size_t *i)
{
	lst->sign = 1;
	lst->pre = 0;
	lst->wid = 0;
	lst->pre_flag = 0;
	while (ft_isdigit(fmt[*i]))
		lst->wid = lst->wid * 10 + (fmt[(*i)++] - '0');
	if (fmt[*i] == '.')
	{
		(*i)++;
		lst->pre_flag = 1;
		while (ft_isdigit(fmt[*i]))
			lst->pre = lst->pre * 10 + (fmt[(*i)++] - '0');
	}
}

int ft_print_out(t_lst *lst, const char *fmt)
{
	size_t i = 0;

	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[++i] == '%')
			{
				ft_write_char(lst, '%');
				i++;
			}
			else
			{
				ft_flag(lst, fmt, &i);
				ft_speci(lst, fmt, &i);
			}
		}
		else
			ft_write_char(lst, fmt[i++]);
		if (lst->status == -1)
			return (-1);
	}
	return ((int)lst->len);
}

int ft_printf(const char *fmt, ... )
{
	t_lst *lst;
	int len;

	if (!fmt)
		return (0);
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (-1);
	va_start(lst->args, fmt);
	lst->status = 0;
	lst->len = 0;
	len = ft_print_out(lst, fmt);
	va_end(lst->args);
	free (lst);
	return (len);
}

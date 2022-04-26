#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_lst
{
	va_list args;
	size_t len;
	int	sign;
	int	status;
	int	pre_flag;
	long long wid;
	long long pre;
} t_lst;

int ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
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
	size_t len;
	len = lst->len + ft_strlen(s);
	if (len > INT_MAX)
	{
		lst->status = -1;
		return ;
	}
	lst->len += write(1, s, ft_strlen(s));
}

void ft_write_char(t_lst *lst, int c)
{
	size_t len;
	len = lst->len + 1;
	if (len > INT_MAX)
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
//		ft_itoa(res, -d, i);
//		res[(*i)++] = d % 10 + '0';
		ft_itoa(res, d / 10, i);
		res[(*i)++] = '8';
	}
	else if (d < 0)
		ft_itoa(res, -d, i);
	else if (d > 9)
	{
		ft_itoa(res, d / 10, i);
		ft_itoa(res, d % 10, i);
	}
	else 
//		res[(*i)++] = d % 10 + '0';
		res[(*i)++] = d + '0';
}

int ft_space(t_lst *lst, int i)
{
	int ret = 0;
	
	if (lst->pre < lst->wid && i < lst->wid)
	{
		if (lst->pre < i)
		{
			ret = lst->wid - i;
			if (lst->sign == -1)
				ret--;
		}
		else
		{
			ret = lst->wid - lst->pre;
			if (lst->sign == -1)
				ret--;
		}
	}
	return (ret);
}

int ft_zero(t_lst *lst, int i)
{
	if (lst->pre > i)
		return (lst->pre - i);
	return (0);
}

void ft_deci(t_lst *lst, int d)
{
	char res[15] = {'\0'};
	int i = 0;
//	int j = 0;
	int space;
	int zero;

	ft_itoa(res, d, &i);
	if (d < 0)
		lst->sign = -1;
//	if (i < lst->wid)
	if (lst->pre < lst->wid)
	{
		space = ft_space(lst, i);
		while (0 < space--)
			ft_write_char(lst, ' ');
	}
	if (lst->sign == -1)
		ft_write_char(lst, '-');
	if (i < lst->pre)
	{
		zero = ft_zero(lst, i);
		while (0 < zero--)
			ft_write_char(lst, '0');
	}
//	if (d == 0 && lst->pre_flag == 1 && lst-pre > 0)
	if (d == 0 && lst->pre_flag == 1 && lst->pre == 0)
	{
		if (lst->wid > 0)
			ft_write_char(lst, ' ');
		return ;
	}
//forgot
	ft_write_str(lst, res);
	return ;
}

void ft_itoh(char *base, char *res, unsigned int h, int *i)
{
	if (16 <= h)
		ft_itoh(base, res, h / 16, i);
//	res[(*i)++] = base[h % 16] + '0';
	res[(*i)++] = base[h % 16];
}

void ft_hex(t_lst *lst, unsigned int h)
{
	char res[15] = {'\0'};
	int i = 0;
	int space;
	int zero;

	ft_itoh("0123456789abcdef", res, h, &i);
	if (lst->pre < lst->wid)
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
//forgot
	ft_write_str(lst, res);
	return ;
}

void ft_str(t_lst *lst, char *s)
{
	char null[7] = "(null)";
//	size_t len;
	int len;
	//	size_t i = 0;
	int i = 0;
	int space;
	// forgot
	int word;

	if (!s)
		len = 6 ;
	else
		len = ft_strlen(s);
//	if (len < lst->wid)
//		space = lst->wid - len;
//	if (lst->pre < len)
//		space = lst->wid - lst->pre;

//forgot
	if (lst->pre < len && lst->pre_flag == 1)
		word = lst->pre;
	else
		word = len;
	space = lst->wid - word;
	
	// 	while (len < space)
 	while (0 < space)
	{
		ft_write_char(lst, ' ');
		space--;
	}
//	while (i < len)
	while (i < word)
	{
		if (!s)
			ft_write_char(lst, null[i++]);
		else
			ft_write_char(lst, s[i++]);
	}
}

void ft_speci(t_lst *lst, const char *fmt, int *i)
{
	if (fmt[*i] == 'd')
	{
//		ft_deci(lst, va_arg(lst->va_args, int));
		ft_deci(lst, va_arg(lst->args, int));
		(*i)++;
	}
	else if (fmt[*i] == 'x')
	{
		ft_hex(lst, va_arg(lst->args, unsigned int));
		(*i)++;
	}
	else if (fmt[*i] == 's')
	{
		ft_str(lst, va_arg(lst->args, char *));
		(*i)++;
	}
}

void ft_flag(t_lst *lst, const char *fmt, int *i)
{
	//forgot
	lst->sign = 1;
	lst->wid = 0;
	lst->pre = 0;
	lst->pre_flag = 0;

	while (ft_isdigit(fmt[*i]))
		lst->wid = lst->wid * 10 + (fmt[(*i)++] - '0');
	if (fmt[*i] == '.')
	{
		//forgot
		lst->pre_flag = 1;
		(*i)++;
		while (ft_isdigit(fmt[*i]))
			//forgot ()
			lst->pre = lst->pre * 10 + (fmt[(*i)++] - '0');
	}
}

int ft_print_out(t_lst *lst, const char *fmt)
{
	int i = 0;

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
//	return (0);
	return ((int)lst->len);
}

int ft_printf(const char *fmt, ...)
{
	t_lst *lst;
//	size_t len;
	int len;

	if (!fmt)
		return (0);
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (-1);
	va_start(lst->args, fmt);
	//forgot
	lst->len = 0;
	lst->status = 0;
	//	if (-1 == ft_print_out(lst, fmt)
//		return (-1);
	len = ft_print_out(lst, fmt);
//	len = lst->len;
//	len = (int)lst->len;
	va_end(lst->args);
	free (lst);
	return (len);
}

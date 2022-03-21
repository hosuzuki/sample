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
void ft_str(t_lst *lst, char *s);

int	ft_isdigit(int	c)
{
	return ('0' <= c && c <= '9');
}

size_t ft_strlen(char *str)
{
	size_t i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

void ft_write_str(t_lst *lst, char *str)
{
	size_t total;
	total = lst->len + ft_strlen(str);
	if (total > INT_MAX)
	{
		lst->status = -1;
		return ;
	}
	lst->len += write(1, str, ft_strlen(str));
}

void ft_write_char(t_lst *lst, int c)
{
	size_t total;
	total = lst->len + 1;
	if (total > INT_MAX)
	{
		lst->status = -1;
		return ;
	}
	lst->len += write(1, &c, 1);
}

void	ft_itoa(char *deci, int d, int *i)
{

	if (d == INT_MIN)
	{
		ft_itoa(deci, d /10, i);
		deci[(*i)++] = '8';
	}
	else if (d < 0)
	{
//		deci[(*i)++] = '-';
		ft_itoa(deci, -d, i);
	}
	else if (9 < d)
	{
		ft_itoa(deci, d / 10, i);
		ft_itoa(deci, d % 10, i);
	}
	else
		deci[(*i)++] = d + '0';
}

void ft_deci(t_lst *lst, int d)
{
	char deci[15] = {'\0'};
	int i = 0;
	int len = 0;

	ft_itoa(deci, d, &i);
	if (d < 0)
	{
		lst->sign = -1;
		i++;
	}
	len = i;
	if (len < lst->wid)
		len = lst->wid;
	if (len < lst->pre)
		len = lst->pre;
	while (i < len)
	{
		if (0 <= lst->pre && len <= lst->pre)
		{
			if (lst->sign == -1)
			{
				ft_write_char(lst, '-');
				lst->sign = 0;
				len++;
			}
			ft_write_char(lst, '0');
		}
		else 
			ft_write_char(lst, ' ');
		len--;
	}
	if (lst->sign == -1)
		ft_write_char(lst, '-');
	ft_write_str(lst, deci);
}

void	ft_dtoh(char *res, unsigned int h, char *base, int *i)
{

	if (16 <= h)
		ft_dtoh(res, h / 16, base, i);
	res[(*i)++] = base[h % 16];
}

void ft_hex(t_lst *lst, unsigned int h)
{
	int i = 0;
	//char *hex;
	int len;
	char res[10] = {'\0'};

	ft_dtoh(res, h, "0123456789abcdef", &i);
	len = i;
	if (len < lst->wid)
		len = lst->wid;
	if (len < lst->pre)
		len = lst->pre;
	while (i < len)
	{
		if (0 <= lst->pre && len <= lst->pre)
			ft_write_char(lst, '0');
		else 
			ft_write_char(lst, ' ');
		len--;
	}
	ft_write_str(lst, res);
}

void ft_str(t_lst *lst, char *s)
{
	int len;
	int space;
	int word;
	int i = 0;

	len = ft_strlen(s);
	if (lst->pre < len && lst->sign == -10)
		word = lst->pre;
	else
		word = len;
	space = lst->wid - word;
	while (0 < space)
	{
		ft_write_char(lst, ' ');
		space--;
	}
	while (i < word)
		ft_write_char(lst, s[i++]);
}
void ft_speci(const char *fmt, t_lst *lst, int *i)
{
	if (fmt[*i] == 'd')
		ft_deci(lst, va_arg(lst->args, int));
 	else if (fmt[*i] == 'x')
		ft_hex(lst, va_arg(lst->args, unsigned int));
	else if (fmt[*i] == 's')
		ft_str(lst, va_arg(lst->args, char *));
	(*i)++;
}

void	ft_save_flags(const char *fmt, t_lst *lst, int *i)
{
	lst->sign = 1;
	lst->wid = 0;
	lst->pre  = 0;
	while (ft_isdigit(fmt[*i]))
		lst->wid = lst->wid * 10 + (fmt[(*i)++] - '0');
	if (fmt[*i] == '.')
	{
		lst->sign = -10;
		(*i)++;
		while (ft_isdigit(fmt[*i]))
			lst->pre = lst->pre * 10 + (fmt[(*i)++] - '0');
//		if (lst->pre == -1)
//			lst->pre = 0; // check
	}
}

int	ft_print_out(const char *fmt, t_lst *lst)
{
	int	i = 0;
	while(fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '%')
			{
				ft_write_char(lst, '%');
				i++;
			}
			else
			{
				ft_save_flags(fmt, lst, &i);
				ft_speci(fmt, lst, &i);
			}
		}
		else
			ft_write_char(lst, fmt[i++]);
		if (lst->status == 1)
			return (-1);
	}
	return ((int)lst->len);
}

int	ft_printf(const char *fmt, ...)
{
	t_lst	*lst;
	int	len;
	
	if(!fmt)
		return (0);
	lst = (t_lst *)malloc(sizeof(t_lst));
	if(!lst)
		return (-1);
	va_start(lst->args, fmt);
	lst->len = 0;
	lst->status = 0;
	len = ft_print_out(fmt, lst);
	va_end(lst->args);
	free (lst);
	return (len);
}

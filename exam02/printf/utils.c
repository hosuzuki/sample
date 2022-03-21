#include "ft_printf.h"

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

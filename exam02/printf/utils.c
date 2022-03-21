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
		deci[(*i)++] = '-';
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

	ft_itoa(deci, d, &i);
	ft_write_str(lst, deci);
}

char *ft_dtoh(unsigned int h, char *base, size_t *i)
{
	static char res[10] = {'\0'};

	if (16 <= h)
		ft_dtoh(h / 16, base, i);
	res[(*i)++] = base[h % 16];
	return (res);
}

void ft_hex(t_lst *lst, unsigned int h)
{
	size_t i = 0;
	char *hex;

	hex = ft_dtoh(h, "0123456789abcdef", &i);
	ft_write_str(lst, hex);
}

void ft_str(t_lst *lst, char *s)
{
	ft_write_str(lst, s);
}


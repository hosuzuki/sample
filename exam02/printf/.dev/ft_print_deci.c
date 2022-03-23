#include "ft_printf.h"

static void	ft_print_space_deci(t_stock *lst, size_t len, long long tmp)
{
	if ((long long)len < lst->width)
	{
		if (0 < lst->precision && 0 < lst->width - lst->precision
			&& lst->sign == MINUS)
			tmp += lst->width - lst->precision;
		else if (0 < lst->precision && (long long)len < lst->precision)
			tmp += lst ->precision;
		else
			tmp += len;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}
	else if (0 < lst->precision && lst->precision < lst->width
		&& (long long)len < lst->width)
	{
		tmp += lst->precision;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}
}

static void	ft_print_width_preci_space_deci(t_stock *lst, size_t len)
{
	long long	tmp;

	tmp = 0;
	ft_print_space_deci(lst, len, tmp);
}


static int	count_digits(int n)
{
	int	i;

	i = 1;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	to_alpha(char *res, int n, int *i)
{
	if (n == INT_MIN)
	{
		to_alpha(res, n / 10, i);
		res[(*i)++] = '8';
	}
	else if (n < 0)
	{
		res[(*i)++] = '-';
		to_alpha(res, -n, i);
	}
	else if (n > 9)
	{
		to_alpha(res, n / 10, i);
		to_alpha(res, n % 10, i);
	}
	else
		res[(*i)++] = '0' + n;
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*res;
	int		i;

	digits = count_digits(n);
	res = (char *)malloc((digits + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	to_alpha(res, n, &i);
	res[i] = '\0';
	return (res);
}

void	ft_print_decimal(t_stock *lst, int decimal)
{
	size_t	len;
	char	*res;

	res = ft_itoa(decimal);
	if (!res)
	{
		lst->status = ERROR;
		return ;
	}
	len = ft_strlen(res);
	if (decimal < 0)
		lst->sign = MINUS;
	ft_print_flags_before_deci(lst, len);
	if (res[0] == '-')
		ft_write(lst, res + 1, len - 1);
	else if (lst->precision != 0 || decimal != 0)
		ft_write(lst, res, len);
	if (0 < lst->width && lst->precision == 0 && decimal == 0)
		ft_write(lst, " ", 1);
	free (res);
}

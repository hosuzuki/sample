#include <stdarg.h>

# define ERROR -1
# define GOOD 0
# define OFF -5
# define ON  1
# define PLUS 2
# define MINUS -2

typedef struct s_lst
{
	size_t		len;
	va_list		args;
	int			status;
	int			sign;
	long long	width;
	long long	precision;
}	t_stock;

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9')
}
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

	if (lst->zero_pad == ON && lst->width < lst->precision)
		return ;
	if (lst->zero_pad == ON && lst->precision < 0)
		return ;
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
	res = ft_calloc(digits + 1, sizeof(char));
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

int	ft_analyze_speci(const char *fmt, t_stock *lst, size_t *i)
{
	if (fmt[*i] == 's')
		ft_print_str(lst, va_arg(lst->args, char *));
	else if (fmt[*i] == 'd')
		ft_print_decimal(lst, va_arg(lst->args, int));
	else if (fmt[*i] == 'x')
		ft_print_hex(lst, va_arg(lst->args, unsigned int));
	else if (fmt[*i] == '%')
	{
		if (ERROR == ft_write(lst, "%", 1))
			return (ERROR);
	}
	else
		(*i)--;
	if (lst->status == ERROR)
		return (ERROR);
	return (GOOD);
}

int	ft_analyze_flags(const char *fmt, t_stock *lst, size_t *i)
{
	while (ft_isdigit(fmt[*i]) || fmt[*i] == '.')
	{
		ft_save_width(fmt, lst, i);
		ft_save_precision(fmt, lst, i);
		if (lst->status == ERROR)
			return (ERROR);
	}
	return (GOOD);
}

void	ft_init_lst(t_stock *lst)
{
	lst->total_len = 0;
	lst->status = OFF;
	lst->sign = OFF;
	lst->width = 0;
	lst->precision = OFF;
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


int	ft_analyze_fmt(const char *fmt, t_stock *lst)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(fmt);
	i = 0;
	while (i < len)
	{
		ft_init_lst(lst);
		if (fmt[i] == '%')
		{
			i++;
			if (ERROR == ft_analyze_flags(fmt, lst, &i))
				return (ERROR);
			if (ERROR == ft_analyze_speci(fmt, lst, &i))
				return (ERROR);
			i++;
		}
		else
		{
			if (ERROR == ft_write(lst, (char *)&fmt[i], 1))
				return (ERROR);
			i++;
		}
	}
	return ((int)lst->total_len);
}

int	ft_printf(const char *fmt, ...)
{
	t_stock	*lst;
	int		total_length;

	if (!fmt)
		return (0);
	lst = (t_stock *)malloc(sizeof(t_stock));
	if (!lst)
		return (-1);
	va_start(lst->args, fmt);
	total_length = ft_analyze_fmt(fmt, lst);
	va_end(lst->args);
	free (lst);
	return (total_length);
}

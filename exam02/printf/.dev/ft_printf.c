#include "ft_printf.h"

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
		ft_save_wp(fmt, lst, i);
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

int	ft_analyze_fmt(const char *fmt, t_stock *lst)
{
	size_t	i;

	i = 0;
	while (fmt[i])
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

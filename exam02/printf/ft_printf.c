#include "ft_printf.h"

void ft_speci(const char *fmt, t_lst *lst, int *i)
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
/*	else if (fmt[*i] == 's')
	{
		ft_str(fmt, lst, i);
		(*i)++;
	}
*/}

void	ft_save_flags(const char *fmt, t_lst *lst, int *i)
{
	while (ft_isdigit(fmt[*i]))
		lst->wid = lst->wid * 10 + (fmt[(*i)++] - '0');
	if (fmt[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(fmt[*i]))
			lst->pre = lst->pre * 10 + (fmt[(*i)++] - '0');
		if (lst->pre == 0)
			lst->pre = 1; // check
	}
}

void ft_init_lst(t_lst *lst)
{
	lst->sign = 1;
	lst->wid = 0;
	lst->pre  = 0;
}

int	ft_print_out(const char *fmt, t_lst *lst)
{
	int	i = 0;
	while(fmt[i])
	{
		ft_init_lst(lst);
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

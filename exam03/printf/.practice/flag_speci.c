void ft_save_speci(const char *fmt, t_lst *lst, int *i)
{
	if (fmt[*i] == 'd')
	{
//		ft_deci(fmt, lst)
		ft_deci(lst, va_arg(lst->args, int));
		(*i)++;
	}
	else if (fmt[*i] == 'h')
	{
//		ft_deci(fmt, lst)
		ft_hex(lst, va_arg(lst_args, unsigned in));
		(*i)++;
	}
	else if (fmt[*i] == 's')
	{
	//	ft_deci(fmt, lst)
		ft_str(lst, va_arg(lst_args, char *));
		(*i)++;
	}
}

void ft_save_flags(const char *fmt, t_lst *lst, int *i)
{
	//forgot
	lst->sign = 1;
	//forgot
	lst->wid = 0;
	//forgot
	lst->pre = 0;
	//forgot
	lst->pre_flag = 0;
	while (ft_isdigit(fmt[*i]))
	{
		lst->wid = lst->wid * 10 + (fmt[*i] - '0');
		(*i)++;
	}
	if (fmt[*i] == '.')
	{
		(*i)++;
		lst->pre_flag = 1;
		while (ft_isdigit(fmt[*i]))
		{
//			lst->wid = lst->wid * 10 + fmt[*i] - '0';
			lst->pre = lst->pre * 10 + (fmt[*i] - '0');
			(*i)++;
		}
	}
}

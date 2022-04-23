int ft_printout(const char *fmt, t_lst *lst)
{
	//long i = 0;
	int i = 0

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
				ft_save_flags(lst, fmt, &i);
				ft_save_speci(lst, fmt, &i);
			}
		}
		else
			ft_write_char(lst, fmt[i++]);
		if (lst->status == -1)
			return (-1)
		}
	}
	//	return (lst->len);
	return ((int)lst->len);
}

int ft_printf(const char *fmt, ...)
{
	t_lst *lst;
	int len;

	if (!fmt)
		return (0);
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (-1);
	va_start(lst->args, fmt);
	//forgot
	lst->len = 0;
	//forgot
	lst->status = 0;
	len = ft_printout(fmt, lst);
	va_end(lst->args);
	free (lst);
	return (len);
}

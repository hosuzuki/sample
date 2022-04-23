void ft_deci(t_lst *lst, int d)
{
	char deci[15] = {'\0'};
	int i = 0;
	int j = 0;
	int space = 0;
	int zero = 0;

	ft_itoa(deci, d, &i);
	if (d < 0)
		lst->sign = -1;
	if (lst->pre < lst->wid)
	{
		space = ft_space_deci(lst, i);
		while (j++ < space)
			ft_write_char(lst, ' ');
	}
	if (lst->sign == -1)
		ft_write_char(lst, '-');
	j = 0;
	if (0 < lst->pre)
	{
		zero = ft_zero_deci(lst, i, space);
		while (j++ < zero)
			ft_write_char(lst, '0');
	}
	if (d == 0 && lst->pre == 0 && lst->pre_flag == 1)
	{
		if (0 < lst->wid)
			 ft_write_char(lst, ' ');
		else
			 ft_write_str(lst, "");
		return ;
	}
	ft_write_str(lst, deci);
}



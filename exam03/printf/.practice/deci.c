void ft_deci(t_lst *lst, int d)
{
	int space;
	int zero;
	int i = 0;
	int j = 0;
//	char res[10] = {'\0'};
	char res[15] = {'\0'};

	ft_dtoa(res, d, &i);
	if (0 > d)
		lst->sign = -1;
	if (lst->pre < lst->wid)
	{
		space = ft_space(lst, i);
		while (j++ < space)
			ft_write_char(lst, ' ');
	}
	if (lst->sign == -1)
		ft_wriet_char(lst, '-');
	if (0 < lst->pre)
	{
		j = 0;
		zero = ft_zero(lst, i);
		while (j++ < zero)
	//		ft_write_char(lst, ' ')
			ft_write_char(lst, '0')
	}
	if (d == 0 && lst->pre == 0 && lst->pre_flag = 1)
	{
	//	if 
		if (0 < lst->wid)
			ft_write_char(lst, ' ');
//		else 
//			ft_write_char(lst, "");
		return ;
	}
	ft_write_str(lst, res);
}

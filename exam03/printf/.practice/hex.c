void ft_dtoh(char *base, char *res, unsigned int h, int *i)
{
//	if (i <= 16)
	if (16 <= h)
		ft_htoa(base, res, h / 16, i);
	res[(*i)++] = base[h % 16];
}

void ft_hex(t_lst *lst, unsigned int h)
{
	int len;
	int i = 0;
	char res[10] = {'\0'};

	ft_dtoh("0123456789abcdef", res, h, &i);
	len = i;
	if (len < lst->wid)
		len = lst->wid;
	if (len < lst->pre)
		len = lst->pre;
	while (i < len)
	{
//		if (lst->pre_flag == 1 && i < lst->pre)
		if(lst->pre_flag == 1 && len <= lst->pre)
			ft_write_char(lst, '0');
		else
			ft_write_char(lst, ' ');
		len--;
	}
	ft_write_str(lst, res);
}

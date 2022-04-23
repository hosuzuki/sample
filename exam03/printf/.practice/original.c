void	ft_dtoh(char *res, unsigned int h, char *base, int *i)
{
	if (16 <= h)
		ft_dtoh(res, h / 16, base, i);
	res[(*i)++] = base[h % 16];
}

void ft_hex(t_lst *lst, unsigned int h)
{
	int i = 0;
	int len;
	char res[10] = {'\0'};

	ft_dtoh(res, h, "0123456789abcdef", &i);
	len = i;
	if (len < lst->wid)
		len = lst->wid;
	if (len < lst->pre)
		len = lst->pre;
	while (i < len)
	{
		if (0 <= lst->pre && len <= lst->pre)
			ft_write_char(lst, '0');
		else 
			ft_write_char(lst, ' ');
		len--;
	}
	ft_write_str(lst, res);
}

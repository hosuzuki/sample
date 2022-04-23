void ft_str(t_lst *lst, char *s)
{
	int len;
	int space;
	int word;
	int i = 0;
	char null[7] = "(null)";
	
	len = ft_strlen(s);
	if (len == -1)
		len = 6;
	if (lst->pre < len && lst->pre_flag == 1)
		word = lst->pre;
	else
		word = len;
	space = lst->wid - word;
	while (0 < space)
	{
		ft_write_char(lst, ' ');
		space--;
	}
	if (s == NULL)
		while (i < word)
			ft_write_char(lst, null[i++]);
	else
		while (i < word)
			ft_write_char(lst, s[i++]);
}



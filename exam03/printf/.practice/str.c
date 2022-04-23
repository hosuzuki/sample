void ft_str(t_lst *lst, char *s)
{
	int word;
	int len;
	int space;
	int i = 0;
//	char null[] = "(null)";
	char null[7] = "(null)";

	if (!s)
		len = 6
	else
		len = ft_strlen(s);
	if (lst->pre < len && lst->pre_flag == 1)
		word = lst->pre;
	else 
		word = len;
	//space = lst->wid - len;
	space = lst->wid - word;
	while (0 < space)
	{
		ft_write_char(lst,' ');
		space--;
	}
	while (i < word)
	{
		if (!s)
			ft_write_char(lst, null[i++]);
		else
			ft_write_char(lst, s[i++]);
	}
}

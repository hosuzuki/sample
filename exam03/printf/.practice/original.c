int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

size_t ft_strlen(char *str)
{
	size_t i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

void ft_write_str(t_lst *lst, char *str)
{
	size_t total;
	total = lst->len + ft_strlen(str);
	if (total > INT_MAX)
	{
		lst->status = -1;
		return ;
	}
	lst->len += write(1, str, ft_strlen(str));
}

void ft_write_char(t_lst *lst, int c)
{
	size_t total;
	total = lst->len + 1;
	if (total > INT_MAX)
	{
		lst->status = -1;
		return ;
	}
	lst->len += write(1, &c, 1);
}


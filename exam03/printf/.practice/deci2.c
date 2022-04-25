void ft_itoa(char *deci, int d, int *i)
{
	if (d == INT_MIN)
	{
		ft_itoa(deci, d / 10, i);
		deci[(*i)++] = '8';
	}
	else if (d < 0)
		ft_itoa(deci, -d , i);
	else if (9 < d)
	{
		ft_itoa(deci, d / 10, i);
		ft_itoa(deci, d % 10, i);
	}
	else
//		deci[(*i)++] = d - '0';
		deci[(*i)++] = d + '0';
}

int ft_space_deci(t_lst *lst, int i)
{
	int ret = 0;
	
	if (i < lst->wid && lst->pre < lst->wid)
	{
		if (lst->pre < i)
		{
			ret = lst->wid - i;
			if (lst->sign == -1)
				ret--;
		}
		else
		{
		 ret = lst->wid = lst->pre;
		 if (lst->sign == -1)
				ret--;
		}
	}
	return (ret);
}

int ft_zero_deci(t_lst *lst, int i)
{
	int ret = 0;
	
	if (i < lst->pre && lst->wid <= lst->pre)
		ret = lst->pre - i;
	else if (i < lst->pre && lst->pre < lst->wid)
		ret = lst->pre - i;
	return (ret)
}

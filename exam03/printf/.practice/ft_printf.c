#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct	s_lst
{
	va_list	args;
	size_t	len;
	int	status;
	long	wid;
	long	pre;
	int 	pre_flag;
} t_lst;

void	ft_write_char(t_lst *lst, int c)
{
	if (lst->len + 1 > INT_MAX)
	{
		lst->status = -1;
		return ;
	}
	lst->len += write(1, &c, 1);
}

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

void	ft_save_wid_pre(t_lst	*lst, const char *fmt, long *i)
{
	while (ft_isdigit(fmt[*i]))
		lst->wid = lst->wid * 10 + fmt[(*i)++] - '0';
	if (fmt[*i] == '.')
	{
		lst->pre_flag = 1;
		(*i)++;
		while (ft_isdigit(fmt[*i]))
			lst->pre = lst->pre * 10 + fmt[(*i)++] - '0';
	}
}

long	ft_strlen(char *str)
{
	long i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_print_str(t_lst *lst, char *str)
{
	int i = 0;
	long	space_len;
	long len;
	long word_len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (lst->pre_flag == 1)
	{
		if (lst->pre < len)
			space_len = lst->wid - lst->pre;
		else 
			space_len = lst->wid - len;
	}
	else 
		space_len = lst->wid - len;
	if (lst->pre > len)
		word_len = len;
	else
		word_len = lst->pre;
	if (len < lst->wid)
	{
		while (0 < space_len)
		{
			ft_write_char(lst, ' ');
			space_len--;
		}
	}
	if (lst->pre_flag == 1)
	{
		while (0 < word_len)
		{
			ft_write_char(lst, str[i++]);
			word_len--;
		}
	}
	else
	{
		while (str[i])
			ft_write_char(lst, str[i++]);
	}
}

void	ft_htoa(char *res, unsigned int h, char *base)
{
	static int i;
	
	if (16 < h)
		ft_htoa(res, h / 16, base);
	res[i] = base[h % 16];
	res[i] = '\0';
}

void	ft_print_hex(t_lst *lst, unsigned int h)
{
	char res[11];

	ft_htoa(res, h, "0123456789abcdef");
	(void)lst;
	printf("%s\n", res);
}

void	ft_judge_speci(t_lst	*lst, const char *fmt, long i)
{
	if (fmt[i] == 's')
		ft_print_str(lst, va_arg(lst->args, char *));
	else if (fmt[i] == 'x')
		ft_print_hex(lst, va_arg(lst->args, unsigned int));
}

void	ft_init_lst(t_lst *lst)
{
	lst->status = 0;
	lst->len = 0;
	lst->wid = 0;
	lst->pre = 0;
	lst->pre_flag = 0;
}

int	ft_printf(const char *fmt, ...)
{
	t_lst	lst;
	long i = 0;

	if (!fmt)
		return (0);
	va_start(lst.args, fmt);
	ft_init_lst(&lst);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[++i] == '%')
				ft_write_char(&lst, '%');
			else
			{
				ft_save_wid_pre(&lst, fmt, &i);
				ft_judge_speci(&lst, fmt, i);
			}
		}
		else
			ft_write_char(&lst, fmt[i]);
		i++;
	}
	va_end(lst.args);
	return (lst.len);
}

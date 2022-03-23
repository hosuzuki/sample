#include "ft_printf.h"

static void	ft_print_space_hex(t_stock *lst, size_t len)
{
	long long	tmp;

	tmp = 0;
	if (0 < lst->precision)
	{
		tmp += lst->precision;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}	
	else if (0 < lst->width)
	{
		while (0 < lst->width - tmp - (long long)len)
			ft_write(lst, " ", 1);
	}
}

static char	*ft_dtoh(unsigned int nbr, char *base, size_t len)
{
	static size_t	i;
	static char		res[10];

	i = 0;
	if (len <= nbr)
		ft_dtoh(nbr / len, base, len);
	res[i++] = base[nbr % len];
	res[i] = '\0';
	return (res);
}

void	ft_print_hex(t_stock *lst, unsigned int decimal)
{
	size_t	len;
	char	*hex;

	hex = ft_dtoh(decimal, "0123456789abcdef", 16);
	len = ft_strlen(hex);
	ft_print_space_hex(lst, len);
	ft_print_zero_hex(lst, len);
	ft_write(lst, hex, len);
}

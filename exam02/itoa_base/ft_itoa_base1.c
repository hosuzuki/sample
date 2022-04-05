#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_size(long nb, int base)
{
	int		len = 0;

	if (nb < 0) 
	{
		if (base == 10)
			len++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*tab = "0123456789ABCDEF";
	int		len;
	long	nb;
	
	nb = value;
	len = ft_size(nb, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		if (base == 10)
			str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[len--] = tab[nb % base];
		nb = nb / base;
	}
	return (str);
}

#ifdef TEST
#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_itoa_base(-10, 10));
	return (0);
}
#endif	

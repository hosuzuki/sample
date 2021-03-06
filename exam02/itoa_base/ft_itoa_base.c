#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int		size(long nb, int base)
{
	int		len = 0;

	if (nb < 0 && base == 10)
	{
		len++;
		nb = nb * -1;
	}
	else if (nb < 0)
		nb = nb * -1;
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
	char	tab[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int		i;
	int		o;
	long	nb;
	
	nb = value;
	i = size(nb, base);
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0 && base == 10)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	else if (nb < 0)
		nb = nb * -1;
	while (nb > 0)
	{
		o = nb % base;
		str[i] = tab[o];
		nb = nb / base;
		i--;
	}
	return (str);
}


#ifdef TEST

#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_itoa_base(0x100AB, 16));
	return (0);
}
	
#endif	

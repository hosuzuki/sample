#include <stdlib.h>

int	ft_strlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	char *tab = "0123456789";
	long nb;

	nb = n;
	len = ft_strlen(nb);
	res = (char *)malloc((len + 1) *sizeof(char));
	res[len--] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (0 < nb)
	{
		res[len--] = tab[nb % 10];
		nb /= 10;
	}
	return (res);
}

#ifdef TEST
#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_itoa(-10));
	return (0);
}
#endif

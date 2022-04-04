int ft_base(char c, int str_base)
{
	char *b1 = "0123456789abcdef";
	char *b2 = "0123456789ABCDEF";
	int i = 0;

	while (i < str_base)
	{
		if ( c == b1[i] || c == b2[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	if (!str)
		return (0);
	while (str[i] <= 32 || str[i] == 127)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
		 	sign = -1;
	while (str[i])
	{
		res = res * str_base + ft_base(str[i], str_base);
		i++;
	}
	return (sign * res);
}

#ifdef test
#include <stdio.h>

int main(void)
{
	char *str = "-100ab";
	int i;

	i = ft_atoi_base(str, 16);
	printf("%d\n", i);
	return (0);
}

#endif

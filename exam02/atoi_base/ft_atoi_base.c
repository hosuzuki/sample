int ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int ft_base(char c, int str_base)
{
	char *b1 = "0123456789abcdef";
	char *b2 = "0123456789ABCDEF";
	int i = 0;

	while (i < str_base)
	{
		if (b1[i] == c || b2[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_base(str[i], str_base) != -1)
	{
		res = res * str_base + ft_base(str[i], str_base); // key
		i++;
	//	while (str[i] != '\0' || '0' <= str[i] && str[i] <= '9')
		
	}
	return (res * sign);
}
/*		res *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if ('A' <= str[i] && str[i] <= 'Z')
			res += str[i] - 'A';
		else if ('a' <= str[i] && str[i] <= 'z')
				res += str[i] - 'a';
		i++;
*/
#ifdef TEST
# include <stdio.h>

int main(void)
{
	//char base[] = "123456789abcdef";
	char str[] = "100ab";
	int res;

	res = ft_atoi_base(str, 16);
	printf("res: %d\n", res);
	return (0);
}

#endif

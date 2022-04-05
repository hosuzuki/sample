#include <stdio.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] <= 32 || str[i] == 127)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi("123321"));
	return (0);
}

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int     i;
	int     result;
	int    neg;

	i = 0;  
	result = 0;
	neg = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		neg *= -1;
	else if (str[i] == '+')
		i++;
	while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * neg);
}

int main(void)
{
	int i;
	char deci[5] = "123!";

	i = ft_atoi(deci);
	printf("i: %d\n", i);
	return (0);
}

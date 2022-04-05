int ft_isprime(int i)
{
	int j = 2;
	while (j < i)
	{
		if (i % j == 0)
			return (0);
		j++;
	}
	return (1);
}

int add_prime_sum(int n)
{
	int i = 2;
	int sum = 0;

	if (n < 2)
		return (sum);
	while (i <= n)
	{
		if (ft_isprime(i))
			sum += i;
		i++;
	}
	return (sum);
}

#include <stdio.h>

int main(void)
{
	int i = 0;
	
	i = add_prime_sum(7);
	printf("%d\n", i);
	return (0);
}

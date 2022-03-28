#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar(0);
	else if (9 < n)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0'); // key
}

int ft_atoi(char *str)
{
	int sign = 1;
	int n = 0;
	int i = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (is_digit(str[i]))
		{
			n = n * 10 + str[i] - '0';
			i++;
		}
		else 
			exit (1);
	}
	return (sign * n);
}

int ft_is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_prime_sum(int n)
{
	int i = 2;
	int sum = 0;

	if (n <=  0)
		return (0);
	while (i <= n)
	{
		if (ft_is_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "0", 1);
	else
		ft_putnbr(ft_prime_sum(ft_atoi(argv[1])));
	write (1, "\n", 1);
	return (0);
}

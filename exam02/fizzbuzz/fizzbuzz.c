#include <unistd.h>

void ft_putnbr(int i)
{
	if (9 < i)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int main(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
/*
int ft_multiple_of_15(int i)
{
	int j = 1;
	int a;

	while (j * 15 <= 100)
	{
		a = j * 15;
		if (i == a)
			return (1);
		j++;
	}
	return (0);
}
int ft_multiple_of_3(int i)
{
	int j = 1;
	int a;

	while (j * 3 <= 100)
	{
		a = j * 3;
		if (i == a)
			return (1);
		j++;
	}
	return (0);
}

int ft_multiple_of_5(int i)
{
	int j = 1;
	int a;

	while (j * 5 <= 100)
	{
		a = j * 5;
		if (i == a)
			return (1);
		j++;
	}
	return (0);
}

void ft_putnbr(int i)
{
	char c;
	
	if (9 < i)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		c = i + '0';
		write(1, &c, 1);
	}
}

int main(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (ft_multiple_of_15(i))
			write(1, "fizzbuzz\n", 9);
		else if
			(ft_multiple_of_3(i))
			write(1, "fizz\n", 5);
		else if (ft_multiple_of_5(i))
			write(1, "buzz\n", 5);
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
*/

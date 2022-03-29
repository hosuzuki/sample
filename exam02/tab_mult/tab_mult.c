#include <unistd.h>

int ft_atoi(char *av, int *j)
{
	int res = 0;

	while (av[*j])
	{
		res = res * 10 + (av[*j] - '0');
	 	(*j)++;
	}
	return (res);
}

void ft_putnbr(int n)
{
	char c;
	if (9 < n)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else 
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	int n;
//	char c;

	if (argc != 2 || argv[1] == NULL)
	{
		write(1, "\n", 1);
		return (-1);
	}
	n = ft_atoi(argv[1], &j);
	while (i < 10)
	{
//		c = i + '0';
//		write(1, &c, 1);
		ft_putnbr(i);
		write(1, " x ", 3);
//		write(1, argv[1], j); 
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(n * i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}


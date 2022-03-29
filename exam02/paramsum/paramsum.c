#include <unistd.h>

/*
char *ft_itoa(int a, int len)
{
	int i = 0;
	char res[len + 1];
	
	if (9 < a)
		ft_itoa(a / 10, len);
	else
		res[i++] = a + '0';
	return (res);
}

int ft_len(int i)
{
	int res = 0;
	
	while (i != 0)
	{
		i /= 10;
		res++
	}
	return (res);
}
*/

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (9 < n)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int main(int argc, char **argv)
{
//	char *a;
//	int len = 0;
//	len = ft_len(argc - 1);
//	a = ft_itoa(argc - 1, len);
	(void)argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}


#include <unistd.h>

int ft_atoi(char *av)
{
	int i = 0;
	int res = 0;

	while(av[i])
	{
		res = res * 10 + (av[i] - '0');
		i++;
	}
	return (res);
}

void ft_print_hex(int a, char *base)
{
	if (16 <= a)
	{
		ft_print_hex(a / 16, base);
		ft_print_hex(a % 16, base);
	}
	else
		write(1, &base[a % 16], 1);
}	

void ft_atoi_base(char *av, char *base)
{
	int a;

	a = ft_atoi(av);
	ft_print_hex(a, base);
}

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
	{
		write(1, "\n", 1);
		return (-1);
	}
	ft_atoi_base(argv[1], "0123456789abcdef");
	write(1, "\n", 1);
	return (0);
}

#include <unistd.h>

void ft_putnbr(int i)
{
	if (i < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-i);
	}
	else if (9 < i)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int main(void)
{
	int i = -12345;
	ft_putnbr(i);
	return (0);
}

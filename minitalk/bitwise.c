#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int	ft_validate_base(char *str)
{
	while (*str)
	{
		if (!(32 <= *str && *str <= 126))
			return (0);
		if (*str == '+' || *str == '-')
			return (0);
		if (strchr(str + 1, *str) != NULL)
			return (0);
		str++;
	}
	return (1);
}

static void	ft_print_body(long l_nbr, char *base, int len)
{
	if (l_nbr < 0)
	{
		write(1, "-", 1);
		ft_print_body(-l_nbr, base, len);
	}
	else
	{
		if (l_nbr >= len)
		{
			ft_print_body(l_nbr / len, base, len);
		}
		write(1, &base[l_nbr % len], 1);
		return ;
	}
}

void	ft_putnbr_base(size_t nbr, char *base)
{
	int	len;

	if (!ft_validate_base(base))
		return ;
	len = strlen(base);
	if (len <= 1)
		return ;
	ft_print_body((long)nbr, base, len);
}

int main(void)
{
	unsigned char x, y;

	x = 0xA5;
	ft_putnbr_base(x, "01");
	printf("\n");
//	y = x & 6;
	y = x | 6;
	ft_putnbr_base(6, "01");
	printf("\n");
	ft_putnbr_base(y, "01");
	printf("\n");
	printf("x: %d, y: %d\n", x, y);
	return (0);
}

#include <unistd.h>

//void ft_write_char(int c)
void ft_write_char(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	ft_write_char('%');
	return (0);
}

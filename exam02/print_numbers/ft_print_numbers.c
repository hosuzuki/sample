#include <unistd.h>

void ft_print_numbers(void)
{
	write(1, "0123456789", 10);
}

#ifdef test
int main(void)
{
	ft_print_numbers();
	return 0;
}
#endif

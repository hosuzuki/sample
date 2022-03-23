#include <stdio.h>
#include "../includes/ft_printf.h"

void end(void)__attribute__((destructor));

void end(void)
{
	    system("leaks a.out");
}

int main(void)
{
	ft_printf("%x, %x, %x\n", 107, 107, 107);
	ft_printf("%x\n", 107);
	ft_printf("%x\n", 107);
	ft_printf("%X\n", 107);
	ft_printf("%X\n", 107);
	ft_printf("%X\n", 107);
	ft_printf("%X\n", 107);
	return (0);
}

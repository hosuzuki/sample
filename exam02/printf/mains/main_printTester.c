#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>

void end(void)__attribute__((destructor));

void end(void)
{
	    system("leaks a.out");
}

int main(void)
{
	
	//	ft_printf("%02x\n", -100);
//	ft_printf("%03d\n", 1);
//	ft_printf("%01d\n", 10);
//	printf("%01d\n", 10);
//	PRINT("%01d\n", 10);
/*	PRINT("%u\n", LONG_MAX);
	PRINT("%d\n", INT_MIN);
	PRINT("%d\n", ULONG_MAX);
	PRINT("%d\n", LONG_MIN);
	PRINT("[ %d ]\n", LONG_MIN - 1);
	PRINT("[ %d ]\n", LONG_MIN);
	PRINT("[ %d ]\n", LONG_MIN + 1);
	PRINT("[ %d ]\n", -1);
*/
	return (0);
}

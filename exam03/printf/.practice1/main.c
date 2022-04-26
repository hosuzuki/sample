#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char *fmt, ...);

int main(void)
{
	PRINT("---RETURN: %d\n", PRINT("[%d]\n", 100));
	system("leaks ft.out");
	return (0);
}


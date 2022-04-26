#include <stdio.h>

int ft_printf(const char *fmt, ... );

int main(void)
{
	PRINT("---RETURN: %d\n", PRINT("[%d%s%x]\n", 10, "apple", 100));
	return (0);
}


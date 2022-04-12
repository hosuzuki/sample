#include <stdio.h>

int	ft_printf(const char *fmt, ...);

int main(void)
{
	PRINT("abcde\n");
	PRINT("%1s\n", "test");
	PRINT("%7s\n", "test");
	PRINT("%.s\n", "test");
	PRINT("%.1s\n", "test");
	PRINT("%.7s\n", "test");
	PRINT("%1.5s\n", "testtest");
	PRINT("%1.10s\n", "test");
	PRINT("%5.1s\n", "test");
	PRINT("%5.10s\n", "t");
	PRINT("%10.1s\n", "test");
	PRINT("%10.5s\n", "t");
	PRINT("%5.5s\n", "t");
	PRINT("%5.5s\n", "testtest");
	PRINT("%1.4s\n", "test");
	PRINT("%10.4s\n", "test");
	PRINT("%4.4s\n", "test");
	PRINT("%x\n", 10);
	return (0);
}

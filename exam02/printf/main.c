#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
//simple
	PRINT(" --- Return : %d\n", PRINT("[%d]\n", -12));
	PRINT(" --- Return : %d\n", PRINT("[%d]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 0));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 122382));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "hello"));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "world"));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "hello!!"));
	PRINT(" --- Return : %d\n", PRINT("[%10d]\n", -12));
	PRINT(" --- Return : %d\n", PRINT("[%10d]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%5.10d]\n", -12));

	PRINT(" --- Return : %d\n", PRINT("[%10.5d]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%10x]\n", -12));
	PRINT(" --- Return : %d\n", PRINT("[%10x]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%5.10x]\n", -12));
	PRINT(" --- Return : %d\n", PRINT("[%10.5x]\n", 12));

 	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 0));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 122382));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "hello"));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "world"));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "hello!!"));
	PRINT(" --- Return : %d\n", PRINT("[%10s]\n", "hello"));
	PRINT(" --- Return : %d\n", PRINT("[%2s]\n", "world"));
	PRINT(" --- Return : %d\n", PRINT("[%.s]\n", "hello!!"));
	PRINT(" --- Return : %d\n", PRINT("[%.0s]\n", "hello"));
	PRINT(" --- Return : %d\n", PRINT("[%.3s]\n", "world"));
	PRINT(" --- Return : %d\n", PRINT("[%10.1s]\n", "hello!!"));
	PRINT(" --- Return : %d\n", PRINT("[%12.4s]\n", "hello"));
	PRINT(" --- Return : %d\n", PRINT("[%12.12s]\n", "world"));
	PRINT(" --- Return : %d\n", PRINT("[%10.20s]\n", "hello!!"));
	

	
//	system("leaks ft.out");
	return (0);
}


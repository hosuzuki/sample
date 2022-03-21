#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	PRINT(" --- Return : %d\n", PRINT("[%d]\n", -12));
	PRINT(" --- Return : %d\n", PRINT("[%d]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 0));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 122382));
//	system("leaks ft.out");
	return (0);
}


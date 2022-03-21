#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
//simple
/*
	PRINT(" --- Return : %d\n", PRINT("[%d]\n", -12));
	PRINT(" --- Return : %d\n", PRINT("[%d]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 0));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 122382));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "hello"));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "world"));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "hello!!"));
*/
	PRINT(" --- Return : %d\n", PRINT("[%10d]\n", -12));
	PRINT(" --- Return : %d\n", PRINT("[%10d]\n", 12));
/*
 	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 0));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 12));
	PRINT(" --- Return : %d\n", PRINT("[%x]\n", 122382));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "hello"));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "world"));
	PRINT(" --- Return : %d\n", PRINT("[%s]\n", "hello!!"));
*/	
	
	
	//	system("leaks ft.out");
	return (0);
}


#include <stdio.h>

int main(void)
{
	int i = 8;

	printf(" --- Return : %d\n", printf("[%0*i]\n", 0, i));//8
	printf(" --- Return : %d\n", printf("[%0*i]\n", 1, i));//8
	printf(" --- Return : %d\n", printf("[%0*i]\n", 2, i));//08
	printf(" --- Return : %d\n", printf("[%0*i]\n", 3, i));//008
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 0, 0, i));//8
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 0, 1, i));//8
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 0, 2, i));//08
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 1, 0, i));//8
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 1, 1, i));//8
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 1, 2, i));//08
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 2, 0, i));// 8
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 2, 1, i));// 8
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 2, 2, i));//08
	printf(" --- Return : %d\n", printf("[%0*.*i]\n", 3, 1, i));//  8
	return (0);
}

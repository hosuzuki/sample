#include <stdio.h>

int main(void)
{
	printf("[%1.10d]\n", 100000);
	printf("[%1.10x]\n", 100000);
	printf("[%10.1d]\n", 100000);
	printf("[%10.1x]\n", 100000);
	printf("[%10.5d]\n", 10);
	printf("[%.0d]\n", 0);
	printf("[%10.5x]\n", -10);
	printf("[%10.5x]\n", 10);
	printf("[%.0x]\n", 0);
	printf("%10.5x\n", 100);
	printf("%10.1s\n", "apple");
	printf("%10.1s\n", "apple");
	return (0);
}

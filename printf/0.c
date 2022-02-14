#include <stdio.h>

int main(void)
{
	int i = 0;
	
	printf("[%1d]\n", i);
	printf("[%1.d]\n", i);
	printf("[%1.0d]\n", i);
	printf("[%.1d]\n", i);
	printf("[%1.1d]\n", i);
	printf("[%10d]\n", i);
	printf("[%10.d]\n", i);
	printf("[%10.0d]\n", i);
	printf("[%.10d]\n", i);
	printf("[%10.10d]\n", i);
	return (0);
}

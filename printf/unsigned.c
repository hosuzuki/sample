#include <stdio.h>

int main(void)
{
	unsigned int i;
	
	i = 1;
	printf("%u\n", 1);
	printf("%u\n", -1);
	printf("[%10u]\n", 1);
	printf("[%10u]\n", -1);
	printf("[%10u]\n", (unsigned short)0 - (unsigned short)1);
	printf("[%10u]\n", (unsigned int)0 - (unsigned int)1);
	printf("%u\n", i - 1);
	printf("%u\n", i - 2);
	
	
	return (0);
}

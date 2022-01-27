#include <stdio.h>

int main(void)
{
	printf("[%-*.*f]\n", 10, 2, 1.112);
	printf("[%*d]\n", 10, 1234567);
	return (0);
}

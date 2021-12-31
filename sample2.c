#include <stdio.h>
int main(void)
{
	printf("[%.0f]\n", 123.3);
	printf("[%.0f]\n", 123.4);
	printf("[%.0f]\n", 123.5);
	printf("[%.0f]\n", -123.3);
	printf("[%.0f]\n", -123.4);
	printf("[%.0f]\n", -123.5);
	printf("[%.0f]\n", 1234567.7654321);

	printf("[%.f]\n", 123.3);
	printf("[%.f]\n", 123.4);
	printf("[%.f]\n", 123.5);
	printf("[%.f]\n", -123.3);
	printf("[%.f]\n", -123.4);
	printf("[%.f]\n", -123.5);
	printf("[%.f]\n", 1234567.7654321);

	printf("[%x]\n", 10);
	printf("[%4.3x]\n", 10);
	printf("[%10.4x]\n", 10);
	return (0);
}


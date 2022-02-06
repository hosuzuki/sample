#include <stdio.h>

int main(void)
{
	printf("[%2s]\n", "1234567");
	printf("[%2.2s]\n", "1234567");
	printf("[%1s]\n", "");
	printf("[%2s]\n", "");
	printf("[%3s]\n", "");
	printf("[%4s]\n", "");
	printf("[%5s]\n", "");

	printf("[%1s]\n", "-");
	printf("[%2s]\n", "-");
	printf("[%3s]\n", "-");
	printf("[%4s]\n", "-");
	printf("[%5s]\n", "-");
	return (0);
}

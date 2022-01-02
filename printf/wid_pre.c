#include <stdio.h>

int main(void)
{
	printf("[%0.1d]\n", 10);
	printf("[%0.5d]\n", 10);
	printf("[%10.1d]\n", 10);
	printf("[%10.5d]\n", 10);

	printf("[%0.1f]\n", 123.321);
	printf("[%0.5f]\n", 123.321);
	printf("[%10.1f]\n", 123.321);
	printf("[%10.5f]\n", 123.321);

	printf("[%0.1e]\n", 123.321);
	printf("[%0.5e]\n", 123.321);
	printf("[%10.1e]\n", 123.321);
	printf("[%10.5e]\n", 123.321);

//	printf("[%0.1s]\n", "123.321");
//	printf("[%0.5s]\n", "123.321");
	printf("[%10.1s]\n", "123.321");
	printf("[%10.5s]\n", "123.321");

}

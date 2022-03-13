#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	long long n;

	n = atoi("214748364700");
	printf("n: %lld\n", n);

	n = (long long)atoi("-2147483648");
	printf("n: %lld\n", n);

	return (0);
}

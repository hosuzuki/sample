#include <stdio.h>

int main(void)
{
	unsigned long long i;

	i = 18446744073709551615; // (ULLONG_MAX)
	printf("%u\n", i);
}

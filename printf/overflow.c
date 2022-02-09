#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i;
	int j;
	int a;
	
	i = printf("%x\n", ULLONG_MAX - 1);
	printf("return value: %d\n", i);

	i = printf("%x\n", ULLONG_MAX);
	printf("return value: %d\n", i);

	j = printf("%p\n", "abcdefg");
	printf("return value: %d\n", j);

	a = printf("%u\n", UINT_MAX + 1);
	printf("return value: %d\n", a);

	a = printf("%u\n", ULONG_MAX + 1);
	printf("return value: %d\n", a);

	a = printf("%u\n", ULLONG_MAX);
	printf("return value: %d\n", a);
}

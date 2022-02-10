#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i;
	int j;
	int a;

	printf("%d\n", (size_t)INT_MIN);
	printf("%d\n", (size_t)-1);
	printf("%d\n", (int)(INT_MAX+ 10));
	printf("%d\n", (unsigned long long)INT_MAX);
	
	i = printf("%x\n", ULLONG_MAX - 1); //fffffffe 
	printf("return value: %d\n", i); //9

	i = printf("%x\n", ULLONG_MAX); //ffffffff (UINT_MAX)
	printf("return value: %d\n", i); //9

	i = printf("%x\n", ULLONG_MAX + 1); //0
	printf("return value: %d\n", i); //2

	i = printf("%x\n", ULLONG_MAX + 2); //1
	printf("return value: %d\n", i); //2

	j = printf("%p\n", "abcdefg");
	printf("return value: %d\n", j); //12

	a = printf("%u\n", UINT_MAX - 1); // 4294967294
	printf("return value: %d\n", a); //11

	a = printf("%u\n", UINT_MAX ); // 4294967295(UINT_MAX)
	printf("return value: %d\n", a); //11

	a = printf("%u\n", UINT_MAX + 1); // 0
	printf("return value: %d\n", a); //2

	a = printf("%u\n", ULONG_MAX - 1); //
	printf("return value: %d\n", a); //11

	a = printf("%u\n", ULONG_MAX); //UINT_MAX
	printf("return value: %d\n", a); //11

	a = printf("%u\n", ULONG_MAX + 1); //0
	printf("return value: %d\n", a); //2

	a = printf("%u\n", ULLONG_MAX- 1); //
	printf("return value: %d\n", a); //11

	a = printf("%u\n", ULLONG_MAX); //42994967295 (UINT_MAX)
	printf("return value: %d\n", a); //11

	a = printf("%u\n", ULLONG_MAX + 1); //0
	printf("return value: %d\n", a); //2
}

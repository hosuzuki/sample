#include <limits.h>
#include <stdio.h>

int main(void)
{
/*
	int i;
	
	i = 0;
	while (0)
	{
		printf("%d, ", i);
		i += 10;
	}
*/
/*
	printf("return value is: %d\n", printf("%*d\n", INT_MAX - 3, -1));
	printf("return value is: %d\n", printf("%*d\n", INT_MAX - 2, -1));
	printf("return value is: %d\n", printf("%*d\n", INT_MAX - 1, 1));
	printf("return value is: %d\n", printf("%*d\n", INT_MAX, 1));

	printf("return value is: %d\n", printf("%*d\n", INT_MAX + 1, -1));
	printf("return value is: %d\n", printf("%*d\n", INT_MAX + 2, -1));
	printf("return value is: %d\n", printf("%*d\n", INT_MAX + 3, -1));
	printf("return value is: %d\n", printf("%*d\n", INT_MAX + 4, -1));
*/

	printf("return value is: %d\n", printf("%d\n", INT_MAX - 3));
	printf("return value is: %d\n", printf("%d\n", INT_MAX - 2));
	printf("return value is: %d\n", printf("%d\n", INT_MAX - 1));
	printf("return value is: %d\n", printf("%d\n", INT_MAX));
	printf("return value is: %d\n", printf("%ld\n", INT_MAX + 1));
	printf("return value is: %d\n", printf("%ld\n", (long)INT_MAX + 1));
	printf("return value is: %d\n", printf("%ld\n", (long)INT_MAX + 2));
	printf("return value is: %d\n", printf("%ld\n", (long)INT_MAX + 3));
	printf("return value is: %d\n", printf("%ld\n", (long)INT_MAX + 4));

	return (0);
}

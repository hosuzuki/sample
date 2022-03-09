#include <stdio.h>

int main(void)
{
	short int a;

	a = 11;
	printf("%d << 2 = %d\n", a, a << 2);
	printf("%d >> 2 = %d\n", a, a >> 2);

	a = -11;
	printf("%d << 1 = %d\n", a, a << 1);
	printf("%d >> 1 = %d\n", a, a >> 1);

	return 0;
}

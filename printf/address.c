#include <stdio.h>

int main(void)
{
	int i = 0;
	char *c = "abc";

	printf("%p\n", 10);
	printf("%p\n", 16);
	printf("%p\n", 123);
	printf("%0p\n", i);
	printf("%p\n", c);
	printf("%0p\n", c);
	printf("%#p\n", c);
	printf("%.10p\n", c);
	printf("%+p\n", c);
	return (0);
}

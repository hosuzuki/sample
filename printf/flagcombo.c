#include <stdio.h>

int main(void)
{
	printf("%0-d\n", 10);
	printf("%-0d\n", 10);
	printf("%+-d\n", 10);
	printf("% +d\n", 10);
	printf("% #d\n", 10);
	printf("%# d\n", 10);
	printf("%# d\n", 10);
	printf("%#+d\n", 10);
	printf("%+#d\n", 10);
	printf("%0-d\n", 10);
	return (0);
}

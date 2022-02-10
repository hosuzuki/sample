#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%*d\n", -1000, 100);
	printf("%.*d\n", -1000, 100);
	printf("%*.*d\n", -1000, -100, 100);
	printf("%*.*d\n", -100, -1000, 100);
	return (0);
}

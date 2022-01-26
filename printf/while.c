#include <stdio.h>

int main (void)
{
	int i = -1;
	int j = 0;
	int o = 1;

	if (i)
		printf("print i\n"); 
	if (j)
		printf("print j\n"); //this wou't be printed
	if (o)
		printf("print o\n");
}

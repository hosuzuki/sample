#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *s = NULL;
	printf(" NULL %s NULL \n", s);
	write(1, &s, 1);
	write(1, "\n", 1);
	return (0);
}

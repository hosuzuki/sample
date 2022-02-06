#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char	c;
	char *s = NULL;
	
	c = '\0';
	printf(" NULL %c NULL \n", c);
	write(1, &c, 1);
	write(1, "\n", 1);

	printf(" NULL %s NULL \n", s);
	write(1, &s, 1);
	write(1, "\n", 1);
	return (0);
}

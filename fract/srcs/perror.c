#include <stdio.h>

int main(void)
{
	char *s = NULL;

	if (!s)
	{
		perror("Hello perror!");
		return (1);
	}
	return (0);
}


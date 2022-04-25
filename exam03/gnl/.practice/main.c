#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char *line;

	while (1 == get_next_line(&line))
	{
		printf("%s", line);
		printf("\n");
		free(line);
	}
	printf("%s", line);
	printf("\n");
	free(line);
	system("leaks a.out");
	return (0);
}


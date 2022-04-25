#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char *line;
//
	line = NULL;
	while (1 == get_next_line(&line))
	{
		printf("%s", line);
		printf("\n");
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
//	system("leaks a.out");
	return (0);
}


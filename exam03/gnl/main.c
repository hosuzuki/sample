#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

/*
void end(void)__attribute__((destructor));

void end(void)
{
	    system("leaks get_next_line");
}
*/
int	main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
//	system("leaks get_next_line");
}

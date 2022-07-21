#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
	{
		 perror("heredoc");
		 exit(EXIT_FAILURE);
	}
	line = NULL;
	printf("%d\n", pipefd[0]);
	printf("%d\n", pipefd[1]);
	close (pipefd[0]);
	close (pipefd[1]);
	return (0);
}

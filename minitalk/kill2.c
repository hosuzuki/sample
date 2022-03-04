#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	pid_t result;
	int status;
	int	code;

	pid = fork();
	printf("pid : %d\n", (int)pid);
	if(pid == -1)
		fprintf(stderr, "Error\n\n");
	write(1, "1\n", 2);
	if(pid == 0)
	{
		write(1, "2\n", 2);
		while(1)
		{
			write(1, "3\n", 2);
			printf("Child Process\n");
			sleep(1);
			write(1, "4\n", 2);
		}
	}
	else
	{
		write(1, "5\n", 2);
		sleep(3);
		write(1, "6\n", 2);
		kill(pid, SIGKILL);
		write(1, "7\n", 2);
		result = wait(&status);
		printf("result: %d\n", (int)result);
		write(1, "8\n", 2);
		if(result < 0)
		{
			write(1, "9\n", 2);
			fprintf(stderr, "Wait Error.\n\n");
			write(1, "10\n", 3);
			exit(-1);
		}
		write(1, "11\n", 4);
		if (WIFSIGNALED(status))
		{
			write(1, "12\n", 4);
			printf("End with signal number:%d\n",WTERMSIG(status));
		}
	}
	write(1, "13\n", 3);
	return 0;
}

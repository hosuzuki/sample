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
	int status, code;

	pid = fork();
	if(pid == -1)
		fprintf(stderr, "Error\n\n");
	if(pid == 0)
	{
		while(1)
		{
			printf("Child Process\n");
			sleep(1);
		}
	}
	else
	{
		sleep(3);
		kill(pid, SIGKILL);
		result = wait(&status);
		if(result < 0)
		{
			fprintf(stderr, "Wait Error.\n\n");
			exit(-1);
		}
		if (WIFSIGNALED(status))
			printf("End with signal number:%d\n",WTERMSIG(status));
	}
	return 0;
}

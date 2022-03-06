#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
	int	p_id;

	if ((p_id = fork()) == 0) 
	{
		printf("p_id = %d\n", p_id);
		while (1)
		{
			printf("child process is on process\n");
			sleep(1);
		}
	}
	else
	{
		sleep(3);
		printf("p_id = %d\n", p_id);
		kill(p_id, SIGINT);
		printf("p_id = %d\n", p_id);
		wait(NULL);
		printf("parent process is on process\n");
	}
	return 0;
}

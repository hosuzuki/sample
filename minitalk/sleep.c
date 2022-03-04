#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int signo)
{
	printf("signo is :%d\n", signo);
 	char buf[] = "Signal:Catch";
	write(1, buf, sizeof(buf));
}

int main(void)
{
	pid_t pid;
	
	pid = fork();
	printf("pid : %d\n", (int)pid);
	signal(SIGINT, handler);
	sleep(10);
	write(1, "1\n", 2);
	while(1){}
	//	write(1, "2\n", 2);
//	while(1)
//		sleep(10);
	return 0;
}

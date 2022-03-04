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
	signal(SIGINT, handler);
	while(1)
		sleep(1);
	return 0;
}

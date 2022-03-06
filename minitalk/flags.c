#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signum)
{
	exit (1);
}

int main(void)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	printf("SA_SIGINFO: %d\n", SA_SIGINFO);
	sa.sa_handler = handler;
	sigaction(SIGINT, &sa, NULL);
	while (1){}
	return 0;
}

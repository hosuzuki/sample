#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t sig1 = 0;
volatile sig_atomic_t sig2 = 0;

void handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("8\n");
		sig1 = 1;
	}
	else if (sig1)
	{
		sig2 = 1;
		printf("9\n");
	}
}

int main(void)
{
	struct sigaction act;

	act.sa_handler = &handler;
	act.sa_flags = 0;
	printf("1\n");
	if (sigemptyset(&act.sa_mask) != 0)
		printf("ERROR1\n");
	printf("2\n");
	if (sigaddset(&act.sa_mask, SIGUSR1))
		printf("ERROR2\n");
	printf("3\n");
	printf("SIGUSR1:%d\n", (int)SIGUSR1);
	if (sigaddset(&act.sa_mask, SIGUSR2))
		printf("ERROR3\n");
	printf("4\n");
	printf("SIGUSR2:%d\n", (int)SIGUSR2);
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		printf("ERROR4\n");
	printf("5\n");
	if (sigaction(SIGUSR2, &act, NULL) != 0)
		printf("ERROR5\n");
	printf("6\n");
	while (sig2 == 0)
	{
	}
	printf("7\n");
	return 0;
}

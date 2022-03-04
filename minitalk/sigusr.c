#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t sig1 = 0;
volatile sig_atomic_t sig2 = 0;

void handler(int signum)
{
	printf("5\n");
	if (signum == SIGUSR1)
	{
		printf("6\n");
		sig1 = 1;
	}
	else if (sig1)
	{
		printf("7\n");
		sig2 = 1;
	}
}

int main(void)
{
	if (signal(SIGUSR1, handler) == SIG_ERR)
		printf("Error1\n");
	printf("1\n");
	if (signal(SIGUSR2, handler) == SIG_ERR) 
		printf("Error2\n");
	printf("2\n");
	while (sig2 == 0)
	{}
	printf("4\n");
	return 0;
}

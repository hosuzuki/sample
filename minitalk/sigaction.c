#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int count;

void signal_handler(int signum)
{
	count += 100;
	//	puts("stop");
	write(1, "8", 1);
//	exit(1);
}

int main(void)
{
	struct sigaction sa;

	/*	write(1, "1", 1);
			sigemptyset(&sa.sa_mask);//clean signal mask of sa.
			write(1, "2", 1);
			sa.sa_handler = signal_handler; //assigne the signal handler
			write(1, "3", 1);
			sa.sa_flags = 0; 
			write(1, "4", 1);
			sigaction(SIGINT, &sa, NULL);
			write(1, "5", 1);
			while(1){
			}
			write(1, "6", 1);
			return 0;
			*/

	write(1, "1", 1);
	if (-1 == sigemptyset(&sa.sa_mask))
	{
		write(1, "2", 1);
		exit(1);
	}
	write(1, "3", 1);
	sa.sa_handler = signal_handler;
	write(1, "4", 1);
	sa.sa_flags = 0;
	write(1, "5", 1);
	if (-1 == sigaction(SIGINT, &sa, NULL))
	{
		write(1, "6", 1);
		exit(1);
	}
	while(count < 50)
	{}
	write(1, "7", 1);
	return 0;
}

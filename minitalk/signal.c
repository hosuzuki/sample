#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler1(int signal)
{}

void handler2(int signal)
{
//	write(STDERR_FILENO, ".", 1);
//	write(1, ".", 1);
	write(1, "6", 1);
	alarm(5);
	write(1, "7", 1);
}

//int main(const int argc, const char *argv)
int main()
{
	write(1, "1", 1);
	signal(SIGINT, handler1);
	write(1, "2", 1);
	signal(SIGALRM, handler2);
	write(1, "3", 1);
	alarm(2);
	write(1, "4", 1);
	while(1) {}
	write(1, "5", 1);
	return 0;
}

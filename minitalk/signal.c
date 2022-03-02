#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler1(int signal)
{}

void handler2(int signal)
{
	write(STDERR_FILENO, ".", 1);
	alarm(5);
}

//int main(const int argc, const char *argv)
int main()
{
	signal(SIGINT, handler1);
	signal(SIGALRM, handler2);
	alarm(5);
	while(1) {}
	return 0;
}

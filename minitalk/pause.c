#include <signal.h>
#include <unistd.h>

void handler(int signo) {
	char buf[] = "Signal:Catch";
	write(1, buf, sizeof(buf));
}

int main(void)
{
	signal(SIGINT, handler);
//	pause();
	while (1)
		pause();
	return 0;
}

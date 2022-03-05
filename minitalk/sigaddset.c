#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void handler(int num)
{
	char *mes = "signal get\n";
	write( 1, mes, strlen(mes));
}

int main() {
	ssize_t ret;
	char buf[256];
	struct sigaction sa;
	sigset_t unblock_mask;
	sigset_t block_mask;

	sa.sa_handler = handler;
	printf("1\n");
	sa.sa_flags = SA_RESTART; 
	printf("2\n");
	sigemptyset(&block_mask);
	printf("3\n");
	sigaddset(&block_mask, SIGINT);
	printf("4\n");
	sigprocmask(SIG_SETMASK, &block_mask, &unblock_mask);
	printf("5\n");
	sigaction(SIGINT, &sa, 0);
	printf("6\n");
	sigprocmask(SIG_SETMASK, &unblock_mask, NULL);
	printf("7\n");
	ret = read(0, buf, sizeof(buf));
	printf("8\n");
	sigprocmask(SIG_SETMASK, &block_mask, &unblock_mask);
	printf("9\n");
	sleep(10);
	printf("10\n");
	write(1, buf, ret);
	return 0;
}


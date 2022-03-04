#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static volatile long long c1 = 0, c2 = 0, c3 = 0;

void handler(int sig) {
	c1++;
	c2++;
	c3++;
	alarm(1);
}

int main(void) {
	sigset_t set, oset;
	sigemptyset(&set); //initialize the signal mask
	sigaddset(&set, SIGALRM); //adding a signal to the signal mask 
	signal(SIGALRM, handler);
	alarm(1);
	for (long long i = 0; i < 50000000; i++) {
		sigprocmask(SIG_BLOCK, &set, &oset);   //block
		c1++;
		c2++;
		c3++;
		sigprocmask(SIG_SETMASK, &oset, NULL); //cancel the block
	}
	printf("%lld, %lld, %lld\n", c1, c2, c3);
}

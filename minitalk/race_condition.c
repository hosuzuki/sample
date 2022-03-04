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
	signal(SIGALRM, handler);
	alarm(1);
	for (long long i = 0; i < 50000000000; i++) {
		c1++;
		c2++;
		c3++;
	}
	printf("%lld, %lld, %lld\n", c1, c2, c3);
}


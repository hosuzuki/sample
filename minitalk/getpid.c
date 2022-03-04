#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) 
{
	pid_t my_pid;
	pid_t ppid;

	my_pid = getpid();
	ppid = getppid();
	printf("my_pid=%d, ppid=%d\n", (int)my_pid, (int)ppid);
	return 0;
}

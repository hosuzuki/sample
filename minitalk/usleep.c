#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int microsecond = 1.5 * 1000000;

	printf("Stop for %d μ secoonds\n", microsecond);
	usleep(microsecond);
	printf("Stoped for %d μ seconds\n", microsecond);
	return 0;
}

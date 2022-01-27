#include <stdio.h>

int main(void)
{
	//'-'flag
	printf("[%10d]\n", 1);
	printf("[%-10d]\n", 1);

	printf("[%10f]\n", 1.0);
	printf("[%-10f]\n", 1.0);

	printf("[%10s]\n", "1234");
	printf("[%-10s]\n", "1234");

	//'0'flag
	printf("[%10d]\n", 1);
	printf("[%010d]\n", 1);

	printf("[%10f]\n", 1.0);
	printf("[%010f]\n", 1.0);
	printf("[%010f]\n", -1.0);

	//'+'flag
	printf("[%+d]\n", 1);
	printf("[%+d]\n", -1);

	printf("[%+f]\n", 1.0);
	printf("[%+f]\n", -1.0);

	//'(space)'flag
	printf("[% d]\n", 1);
	printf("[% d]\n", -1);

	printf("[% f]\n", 1.0);
	printf("[% f]\n", -1.0);

	printf("[%10d]\n", 1);
	printf("[% 10d]\n", 1);
	printf("[%10d]\n", -1);
	printf("[% 10d]\n", -1);

	printf("[%10f]\n", 1.0);
	printf("[% 10f]\n", 1.0);
	printf("[%10f]\n", -1.0);
	printf("[% 10f]\n", -1.0);

	printf("[%-10f]\n", 1.0);
	printf("[%-10f]\n", -1.0);

	//'#"flag
	printf("[%o]\n", 10);
	printf("[%#o]\n", 10);

	printf("[%x]\n", 10);
	printf("[%#x]\n", 10);

	printf("[%X]\n", 10);
	printf("[%#X]\n", 10);

	printf("[%.0f]\n", 1.0);
	printf("[%#.0f]\n", 1.0);

	printf("[%g]\n", 1.0);
	printf("[%#g]\n", 1.0);
	printf("[%#.0g]\n", 1.0);

	printf("[%G]\n", 1.0);
	printf("[%#G]\n", 1.0);
	printf("[%#.0G]\n", 1.0);
}

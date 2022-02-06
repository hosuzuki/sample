#include <stdio.h>

int main(void)
{
	printf("[% s]\n", "-" );
	printf("[% s]\n", "" );
	printf("[% s]\n", "12345" );
	printf("[% 10s]\n", "12345" );
	printf("[% 2s]\n", "12345" );
	printf("[% .10s]\n", "12345" );
	printf("[% .2s]\n", "12345" );
	printf("[% 2.3s]\n", "12345" );
	printf("[% 3.2s]\n", "12345" );
}

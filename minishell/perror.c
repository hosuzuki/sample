#include <stdio.h>
#include <errno.h>

int main(void)
{
	errno = 0;
	perror( "エラーなし" );
	errno = 1;
	perror( NULL );
	errno = ERANGE;
	perror( NULL );
}


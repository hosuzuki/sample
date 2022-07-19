#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	puts( strerror(0) );
	puts( strerror(ERANGE) );
}

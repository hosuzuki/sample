#include <stdio.h>
#include <stdarg.h>


void miniprint(const char *fmt, ...)
{
	va_list args;
	int i;
//	char *c;


	va_start(args, fmt);
//	c = va_arg(args, char *);
	i = va_arg(args, int);
	printf("c: %d\n", i);
	va_end(args);
}

int main(void)
{
	miniprint("a", 12);
	return (0);
}


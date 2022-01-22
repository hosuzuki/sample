#include <stdio.h>
#include <stdarg.h>

int ft_printf(const char *fmt, ...)
{
	va_list args;
	char *s;

	va_start(args, fmt);
	s = va_arg(args, char *);
	printf("%s\n", s);
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("a", "aa");
}

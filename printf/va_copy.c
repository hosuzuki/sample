#include <stdio.h>
#include <stdarg.h>

int ft_printf(const char *fmt, ...);

int main(void)
{
	ft_printf("Hello", 1, 2, 3);
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	va_list args;
	va_list args2;
	int i;
	int j;

	va_start(args, fmt);
	va_copy(args2, args);
	i = va_arg(args2, int);
	j = va_arg(args, int);
	printf("args2 is: %d\n", i);
	printf("args is: %d\n", j);
	i = va_arg(args2, int);
	printf("args2 is: %d\n", i);
	va_copy(args, args2);
	j = va_arg(args, int);
	printf("args is: %d\n", j);
	va_end(args);
	va_end(args2);
	return (0);
}

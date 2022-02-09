#include <stdio.h>
#include <stdarg.h>

int main(void)
{
	ft_printf("Hello", 1, 2, 3);
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	va_list args;


	va_start(args, fmt);
	va_copy(


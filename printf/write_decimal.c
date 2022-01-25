#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void ft_write_decimal(size_t decimal)
{
	size_t test;
	
	test = 10;
//	write(1, &decimal, 1); // doesn't print decimal.
//	write(1, &test, 1); // doesn't print test, but '\n' is outputed.
	printf("decimal:%zu\n", decimal);
	printf("test:%zu\n", test);
	write(1, "\n", 1);
}

int ft_printf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	ft_write_decimal(va_arg(args, size_t));
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("a", 1);
}

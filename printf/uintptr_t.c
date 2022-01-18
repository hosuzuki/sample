#include <stdio.h>
#include <stdarg.h>

int ft_printf(const char *fmt, ...)
{
	uintptr_t uptr;
	intptr_t ptr; 
	size_t st;
	va_list	args;

	va_start(args, fmt);
	uptr = va_arg(args, uintptr_t);
	ptr = va_arg(args, intptr_t);
	st = va_arg(args, size_t);
	printf("uptr is: %lu\n", uptr);
	printf("ptr is:  %lu\n", ptr);
	printf("st is:   %zu\n", st);
	va_end(args);
	return (0);
}

int main(void)
{
	int a;
	int	*b;
	char	*s;

	a = 10;
	b = &a;

	printf("a's address is: %p\n", &a);
	printf("b is:           %p\n", b);
	printf("b's address is: %p\n", &b);
	printf("a is:           %d\n", a);
	printf("*b is:          %d\n", *b);
	ft_printf("", b, b, b);

	s = "apple apple apple apple apple apple";
	printf("s's address is: %p\n", &s);
	printf("s is:           %s\n", s);
	ft_printf("", s, s, s);

	return (0);
}

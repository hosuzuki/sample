#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks a.out");
}

int main(void)
{
//	ft_printf("[%10x]\n", 1);
	printf("%+x\n", UINT_MAX);
	printf("% x\n", UINT_MAX);
	printf("%x\n", UINT_MAX);
	printf("%x\n", UINT_MAX + 1);
	printf("%x\n", UINT_MAX + 2);
	printf("%x\n", UINT_MAX + 3);

	printf("[%10x]\n", -1);
	printf("%u\n", -1);
	printf("[%10x]\n", -100);
	printf("[%10x]\n", 1);
//	ft_printf("[%10.x]\n", 1);
	printf("[%10.x]\n", 1);

//	ft_printf("[%10.2x]\n", 1);
	printf("[%10.2x]\n", 1);
//	ft_printf("[%2.10x]\n", 1);
	printf("[%2.10x]\n", 1);

//	ft_printf("[%.x]\n", 1);
	printf("[%.x]\n", 1);

//	ft_printf("[%.10x]\n", 1);
	printf("[%.10x]\n", 1);

	printf("[%0.10x]\n", 1);
	
}

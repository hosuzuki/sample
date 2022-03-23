#include "../includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

void end(void)__attribute__((destructor));

void end(void)
{
	    system("leaks a.out");
}

int main(void)
{
	int i;
	int j;
	int a;

	printf("d, ULLONG_MAX - 1\n");
	i = printf("%d\n", ULLONG_MAX - 1); //
	printf("return value: %d\n", i); //
	i = ft_printf("%d\n", ULLONG_MAX - 1); //
	printf("return value: %d\n", i); //
	printf("\n");

	printf("d, ULLONG_MAX\n");
	i = printf("%d\n", ULLONG_MAX); //
	printf("return value: %d\n", i); //
	i = ft_printf("%d\n", ULLONG_MAX); //
	printf("return value: %d\n", i); //
	printf("\n");

	printf("x, ULLONG_MAX - 1\n");
	i = printf("%x\n", ULLONG_MAX - 1); //fffffffe 
	printf("return value: %d\n", i); //9
	i = ft_printf("%x\n", ULLONG_MAX - 1); //fffffffe 
	printf("return value: %d\n", i); //9
	printf("\n");

	printf("x, ULLONG_MAX\n");
	i = printf("%x\n", ULLONG_MAX); //ffffffff (UINT_MAX)
	printf("return value: %d\n", i); //9
	i = ft_printf("%x\n", ULLONG_MAX); //ffffffff (UINT_MAX)
	printf("return value: %d\n", i); //9
	printf("\n");

	printf("x, ULLONG_MAX + 1\n");
	i = printf("%x\n", ULLONG_MAX + 1); //ffffffff (UINT_MAX)
	printf("return value: %d\n", i); //9
	i = ft_printf("%x\n", ULLONG_MAX + 1); //ffffffff (UINT_MAX)
	printf("return value: %d\n", i); //9
	printf("\n");

	printf("x, ULLONG_MAX - 1\n");
	a = printf("%u\n", ULLONG_MAX- 1); //
	printf("return value: %d\n", a); //11
	a = ft_printf("%u\n", ULLONG_MAX- 1); //
	printf("return value: %d\n", a); //11
	printf("\n");

	printf("x, ULLONG_MAX\n");
	a = printf("%u\n", ULLONG_MAX); //42994967295 (UINT_MAX)
	printf("return value: %d\n", a); //11
	a = ft_printf("%u\n", ULLONG_MAX); //42994967295 (UINT_MAX)
	printf("return value: %d\n", a); //11
	printf("\n");

	printf("x, ULLONG_MAX + 1\n");
	a = printf("%u\n", ULLONG_MAX + 1); //0
	printf("return value: %d\n", a); //2
	a = ft_printf("%u\n", ULLONG_MAX + 1); //0
	printf("return value: %d\n", a); //2
//	printf("return value: %d\n", ft_printf("%*d\n", INT_MAX - 1, 1)); // 000
//	printf("return value :%d\n", printf("%*d\n", INT_MAX - 1, 1)); // 000

	ft_printf("[%15.10x]\n", 108); // 000
	printf("[%15.10x]\n", 108); // 000

	ft_printf("[%-15.10x]\n", 108); // 000
	printf("[%-15.10x]\n", 108); // 000

	ft_printf("[% 10d ]\n", -1);
	printf("[% 10d ]\n", -1);

	ft_printf("[%- 10d ]\n", -1);
	printf("[%- 10d ]\n", -1);

	ft_printf("[% d ]\n", -1);
	printf("[% d ]\n", -1);
	
	ft_printf("[ %d ]\n", INT_MIN);

	printf("[ %d  ]\n", -1);
	ft_printf("[ %d  ]\n", -1);
	
	printf("[%10d]\n", -123);
	ft_printf("[%10d]\n", -123);

	ft_printf("[ %c ]\n", '0');
	printf("[ %c ]\n", '0');

	printf("[% d]\n", -1);
	ft_printf("[% d]\n", -1);

	printf("[% d]\n", 0);
	ft_printf("[% d]\n", 0);

	ft_printf("[% s]\n", "-");
	printf("[% s]\n", "-");

	ft_printf("[% s]\n", "");
	printf("[% s]\n", "");

	ft_printf("%#x\n", 0);//zenn
	printf("%#x\n", 0);//zenn

	ft_printf("%-s\n", "-");
	printf("%-s\n", "-");
	
	ft_printf("%.s\n", "-"); // zenn
	printf("%.s\n", "-"); // zenn

	ft_printf("[%04x]\n", 9);
	printf("[%04x]\n", 9);

	ft_printf("[%.2x]\n", 1); //zenn
	printf("[%.2x]\n", 1); //zenn

	ft_printf("[%.1s %.2s %.3s %.4s]\n", " - ", "", "4", "");
	printf("[%.1s %.2s %.3s %.4s]\n", " - ", "", "4", "");

	ft_printf("[ %010d ]\n", INT_MIN);
	printf("[ %010d ]\n", INT_MIN);

	ft_printf("[ %04d ]\n", -14);
	printf("[ %04d ]\n", -14);

	ft_printf("[ %-13p %-14p ]\n", ULONG_MAX, -ULONG_MAX);
	printf("[ %-13p %-14p ]\n", ULONG_MAX, -ULONG_MAX);

	ft_printf("[ %-11p %-12p ]\n", INT_MIN, INT_MAX);
//	printf("[ %-11p %-12p ]\n", INT_MIN, INT_MAX);

	ft_printf("[%1s]\n", "");
	printf("[%1s]\n", "");

	ft_printf("[ %-2c ]\n", '0');
	printf("[ %-2c ]\n", '0');

	ft_printf(" %d \n", 10);
	printf(" %d \n", 10);

	ft_printf(" NULL %s NULL \n", NULL);
	//printf(" NULL %s NULL ", NULL);

	ft_printf("s is : %s\n", "abcde");
	printf("s is : %s\n", "abcde");

	ft_printf("a\n");
	printf("a\n");

	ft_printf("[%-10d]\n", 1);
	printf("[%-10d]\n", 1);

	ft_printf("[%010d]\n", 1);
	printf("[%010d]\n", 1);
	
	ft_printf("%+d\n", 1);
	printf("%+d\n", 1);

	ft_printf("%+d\n", 0);
	printf("%+d\n", 0);

	ft_printf("[% d]\n", 1);
	printf("[% d]\n", 1);

	ft_printf("[%.10d]\n", 1);
	printf("[%.10d]\n", 1);

	ft_printf("[%+10d]\n", 123);
	printf("[%+10d]\n", 123);

	ft_printf("[%.10d]\n", -1);
	printf("[%.10d]\n", -1);

	ft_printf("[%10d]\n", 123);
	printf("[%10d]\n", 123);

	char *s = "abcde";
	char *n = NULL;

	ft_printf("%p\n", s);
	printf("%p\n", s);

	ft_printf("%p\n", n);
	printf("%p\n", n);

	ft_printf("[%-15p]\n", s);
	printf("[%-15p]\n", s);

	ft_printf("[%3p]\n", s);
	printf("[%3p]\n", s);

	ft_printf("%#p\n", s);
	printf("%#p\n", s); //reuslts in undefined behavior

	ft_printf("% p\n", s);
	printf("% p\n", s);// results in undefined behavior

	ft_printf("%0p\n", s);
	printf("%0p\n", s); //results in undefined behavior

	ft_printf("%+p\n", s);
	printf("%+p\n", s); // results in undefined behavior

	ft_printf("[%20p]\n", s);
	printf("[%20p]\n", s);

	ft_printf("[%.20p]\n", s);
	printf("[%.20p]\n", s); // reuslts in undefined behavior

	ft_printf("%%,%d\n", 123);
	printf("%%,%d\n", 123);

	ft_printf("[%10u]\n", 1);
	printf("[%10u]\n", 1);

	ft_printf("[%10u]\n", -1);
	printf("[%10u]\n", -1);

	ft_printf("[%10x]\n", 108);
	printf("[%10x]\n", 108);
	
	ft_printf("%#x\n", 108); 
	printf("%#x\n", 108); 
//	printf("% x\n", 108);// results in undefined behavior
	ft_printf("%0x\n", 108); //results in undefined behavior
	printf("%0x\n", 108); //results in undefined behavior
//	printf("%+x\n", 108); // results in undefined behavior
	ft_printf("%-x\n", 108);
	printf("%-x\n", 108);


	ft_printf("[%-10.10x]\n", 108); //000
	printf("[%-10.10x]\n", 108); //000

	ft_printf("[%10x]\n", 108);
	printf("[%10x]\n", 108);

	ft_printf("[%.10x]\n", 108); //000
	printf("[%.10x]\n", 108); //000

	ft_printf("[%-10x]\n", 108);
	printf("[%-10x]\n", 108);

	ft_printf("[%-.10x]\n", 108); // 000
	printf("[%-.10x]\n", 108); // 000

	ft_printf("[%5.10x]\n", 108); // 000
	printf("[%5.10x]\n", 108); // 000

	ft_printf("[%15.10x]\n", 108); // 000
	printf("[%15.10x]\n", 108); // 000

	ft_printf("[%-15.10x]\n", 108); // 000
	printf("[%-15.10x]\n", 108); // 000

	return (0);
}

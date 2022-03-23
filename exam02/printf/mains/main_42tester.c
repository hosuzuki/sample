#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>

void end(void)__attribute__((destructor));

void end(void)
{
	    system("leaks a.out");
}

int main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	PRINT(" --- Return : %d\n", PRINT("[%4d]\n", j)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%3.2d]\n", i)); //T23
//"%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d" // 1st '*' = 3, 2nd '*' = 2
	PRINT(" --- Return : %d\n", PRINT("[%4d]\n", j)); //T23
	PRINT(" --- Return : %d\n", PRINT("%4d, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
//	PRINT(" --- Return : %d\n", PRINT("[%*.*i]\n", 3, 2, a)); //T23
//	"%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d" // 1st '*' = 3, 2nd '*' = 2
	
//	PRINT(" --- Return : %d\n", PRINT("[%*.*d]\n", 2, 1, k)); //T23
//	PRINT(" --- Return : %d\n", PRINT("[%*.*d]\n", 2, 1, j)); //T23
	
//	PRINT(" --- Return : %d\n", PRINT("[%02i]\n", i)); //T23
//	PRINT(" --- Return : %d\n", PRINT("[%2i]\n", i)); //T23
//	PRINT(" --- Return : %d\n", PRINT("[%0*.*i]\n", 2, 0, i)); //T23
//PRINT(" --- Return : %d\n", PRINT("[%*.*i]\n", -2, 2, i)); //T23
//	PRINT(" --- Return : %d\n", PRINT("[%0*i]\n", -4, i)); //T23
//	PRINT(" --- Return : %d\n", PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	
//	PRINT(" --- Return : %d\n", PRINT("[%*.*d]\n", -4, -2, 8)); //T23
//	PRINT(" --- Return : %d\n", PRINT("[%*.*d]\n", 1, 2, 8)); //T23
//	PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	PRINT(" --- Return : %d\n", PRINT("[%.1d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%1.1d]\n", l)); //T23
//	PRINT(" --- Return : %d\n", PRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d)); //T24
	PRINT(" --- Return : %d\n", PRINT("[%0.d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%0.0d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%0.d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%0.0d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("%1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
PRINT(" --- Return : %d\n", PRINT("%0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
	PRINT(" --- Return : %d\n", PRINT("[%1.d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%1.0d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%10.d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%10.0d]\n", l)); //T23
	PRINT(" --- Return : %d\n", PRINT("%1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
//	PRINT(" --- Return : %d\n", PRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
//	printf(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6



/*	printf(" => %d\n", printf("%.0d", 123));
	printf(" => %d\n", ft_printf("%.0d", 123));

	printf(" => %d\n", printf("%0.d", l));
	printf(" => %d\n", ft_printf("%0.d", l));

	printf(" => %d\n", printf("%0d", l));
	printf(" => %d\n", ft_printf("%0d", l));

	printf(" => %d\n", printf("%.d", l));
	printf(" => %d\n", ft_printf("%.d", l));
*/
	(void)r;
	(void)n;
	(void)p;
	(void)u;
	(void)g;
	(void)b;
	(void)h;
	(void)q;
	(void)o;
	(void)t;
	(void)s;
	(void)a;
	(void)f;
	return (0);
}

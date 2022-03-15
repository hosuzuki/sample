#include <stdio.h>
#include <limits.h>

int main(void)
{
	long long res_max;
	long long res_min;

	res_max = INT_MAX / 10;
	printf("res_max:%lld\n", res_max);
	if (res_max > (INT_MAX - 9) / 10)
		printf("1\n");
	if (res_max * 10 + 9 > (long long)INT_MAX)
		printf("2\n");
		
	res_min = INT_MIN / 10;
	if(res_min < (INT_MIN + 9) / 10)
		printf("3\n");
	if(res_min * 10 - 9  < (long long)INT_MIN)
		printf("4\n");
	return (0);
}

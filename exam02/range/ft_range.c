#include <stdlib.h>

int	*ft_range(int start, int end)
{
	long long  len;
	int *res;
	int i = 0;
	
	len = end - start + 1;
	res = (int *)malloc(sizeof(int));
	if (!res)
		return (NULL);
	while (i <= len)
	{
		res[i] = start + i;
		i++;
	}
	return (res);
}

#ifdef TEST
#include <stdio.h>

int main(void)
{
	int *res;
	int i = 0;

	res = ft_range(-2, 5);
	if(!res)
		return (-1);
	while (i < 8)
		printf("%d\n", res[i++]);
//`	printf("size: %lu\n", sizeof(res) / sizeof(int));
}

#endif

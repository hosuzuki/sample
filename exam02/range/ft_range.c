#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	long long len;
	int *res;
	int i = 0;
	
	len = end - start + 1;
//	if (len < 0)
//		len *= -1;
	printf("len: %lld\n", len);
	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = start + i;
		i++;
	}
	printf ("i: %d\n", i);
	return (res);
}

#ifdef TEST
#include <stdio.h>

int main(void)
{
	int *res;
	int i = 0;

	res = ft_range(-20, -10);
	if(!res)
		return (-1);
	while (i < 15)
		printf("%d\n", res[i++]);
//`	printf("size: %lu\n", sizeof(res) / sizeof(int));
}

#endif

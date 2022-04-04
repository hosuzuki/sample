#include <stdlib.h>
#include <stdio.h>

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int		*ft_range(int start, int end)
{
	int i;
	int *tab;

	i = 0;
	tab = (int*)malloc(sizeof(int) * ft_abs(start - end) + 1);
	if (start == end)
		tab[i] = start;
	else if (start < end)
	{
		while (start < end)
			tab[i++] = start++;
		tab[i] = start;
	}
	else if (start > end)
	{
		while (start > end)
			tab[i++] = start--;
		tab[i] = start;
	}
	return (tab);
}
/*
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
*/

#ifdef TEST
#include <stdio.h>

int main(void)
{
	int *res;
	int i = 0;

	res = ft_range(0, -3);
	if(!res)
		return (-1);
	while (i < 4)
		printf("%d\n", res[i++]);
//`	printf("size: %lu\n", sizeof(res) / sizeof(int));
}

#endif

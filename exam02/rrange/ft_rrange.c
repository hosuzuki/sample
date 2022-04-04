#include <stdlib.h>

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	*ft_rrange(int start, int end)
{
//	long long len;
	int *res;
	int i = 0;

/*
len = end - start;
	if (len < 0)
		len *= -1;
	len++;
*/
	res = (int *)malloc(sizeof(int) * ft_abs(end - start) + 1);
	if (!res)
		return (NULL);
	if (start == end)
		res[i] = start;
	else if (start < end)
	{
		while (start <= end)
			res[i++] = end--;
	}
	else
	{
		while (start >= end)
			res[i++] = end++;
	}
	return (res);
}

#ifdef TEST
# include <stdio.h>

int main(void)
{
 int *res;

 res = ft_rrange(-3, 0);
 int i = 0;
 while (i < 4)
	 printf("%d\n", res[i++]);
 return (0);
}
#endif

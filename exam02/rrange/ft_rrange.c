#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	long long len;
	int *res;
	int i = 0;

	len = end - start;
	if (len < 0)
		len *= -1;
	len++;
	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	if (start < end)
	{
		while (i < len)
		{
			res[i] = end - i;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			res[i] = end + i;
			i++;
		}
	}
	return (res);
}

#ifdef TEST
# include <stdio.h>

int main(void)
{
 int *res;

 res = ft_rrange(-10, -15);
 int i = 0;
 while (i < 6)
	 printf("%d\n", res[i++]);
 return (0);
}
#endif

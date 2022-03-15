#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)b;
	while (i < len)
		dest[i++] = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

static bool	check_bytes(size_t *sum, size_t *count, size_t *size)
{
	if (*count == 0 || *size == 0)
	{
		*count = 1;
		*size = 1;
	}
	*sum = *count * *size;
	if (*sum / *count != *size)
		return (false);
	return (true);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	sum;

	errno = 0;
	if (!check_bytes(&sum, &count, &size))
	{
		errno = ENOMEM;
		return (NULL);
	}
	res = malloc(sum);
	if (!res)
		return (NULL);
	ft_bzero(res, sum);
	return (res);
}

int main(void)
{
	int *str;
	
	str = (int	*)ft_calloc(10, sizeof(int));
	str[0] = 3;
	str[1] = 2;
	str[2] = 1;
	int i = 0;
	while (str[i])
	{
		printf("str[i]: %d\n", str[i]);
		i++;
	}
	printf("str[4]: %d\n", str[4]);
	return (0);
}

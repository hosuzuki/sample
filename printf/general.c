#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
char	*ft_strjoin(const char *s1, char a);

char *ft_overintmax(void)
{
	char	*str1;
	char	a;
	size_t i;

	str1 = (char	*)malloc(sizeof(char) * 2);
	str1[0] = 'a';
	str1[1] = '\0';
	a = 'a';
	i = 0;
	while (i <  2) // INT_MAX 2147483647 
	{
		str1 = ft_strjoin(str1, a);
		if (!str1)
			return (NULL);
		i++;
	}
	return (str1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, char a)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1 + 1));
	if (!dst)
	{
		free ((void *)s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	free ((void *)s1);
	s1 = NULL;
	dst[i++] = a;
	dst[i] = '\0';
	return (dst);
}

int	main(void)
{
	int	i;
//	printf('a'); // cannot compile
//	printf(""); // return value will be 0.
//	printf(); // cannot compile
//	printf("a\n");
//	printf("%ld\n",2147483648);
	i = 0;
	char	*str;
	str = ft_overintmax();
	i = printf("%s", str);
	printf("i is : %d\n", i);
	return (0);
}

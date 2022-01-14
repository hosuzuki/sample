#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
char	*ft_strjoin(const char *s1, const char *s2);

char *ft_overintmax(void)
{
	char	*str1;
	char	*str2;
	size_t i;

	str1 = (char	*)malloc(sizeof(char) * 2);
	str1[0] = 'a';
	str1[1] = '\0';

	str2 = (char	*)malloc(sizeof(char) * 2);
	str2[0] = 'a';
	str2[1] = '\0';

	i = 0;
	while (i < (size_t)INT_MAX + 10)
	{
		str2 = ft_strjoin(str1, str2);
	}
	return (str2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
	{
		free ((void *)s2);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free ((void *)s2);
	return (dst);
}

int	main(void)
{
//	printf('a'); // cannot compile
//	printf(""); // return value will be 0.
//	printf(); // cannot compile
//	printf("a\n");
//	printf("%ld\n",2147483648);

	char	*str;
	str = ft_overintmax();
	printf("%s\n", str);
	return (0);
}

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define LENGTH 10 //change the nubmer to see the resutl

char	*ft_strjoin(const char *s1, char a);

char *ft_create_str(void)
{
	char	*str1;
	char	a;
	size_t i;

	str1 = (char	*)malloc(sizeof(char) * 2);
	str1[0] = 'a';
	str1[1] = '\0';
	a = 'a';
	i = 1;
	while (i <  LENGTH) // INT_MAX 2147483647 
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
	int	r;
	char	*str;

	r = 0;
	str = ft_create_str();
	r = printf("%s", str);
	r = printf("\nreturn value is : %d\n", r);
	r = printf("return value is : %d\n", r);
	return (0);
}

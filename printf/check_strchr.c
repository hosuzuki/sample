#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	printf("s is : %s\n", s);
	printf("s[0] is: %c\n", s[0]);
	printf("c is : %d\n", c);
	printf("(char)c is : %c\n", (char)c);
		i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	main(void)
{
	char	base[] = "01234560";

	ft_strchr(base, *base);
	return (0);
}

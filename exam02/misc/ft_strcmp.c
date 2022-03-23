#include <stdio.h>

int	ft_strcmp(char  *s1, char   *s2)
{
	int     i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}

int main(void)
{
	char one[15] = "helloworld!";
	char two[15] = "helloa!";
	int i;

	i = ft_strcmp(one, two);
	printf("i: %d\n", i);
	return (0);
}

	

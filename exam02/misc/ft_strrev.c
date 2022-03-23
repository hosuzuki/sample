#include <stdio.h>

int     ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strrev(char *str)
{
	int     i;
	char    temp;
	int     len;

	i = 0;
	temp = 0;
	len = ft_strlen(str);
	len--;
	while (len > i)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return(str);
}

int main(void)
{
	char one[15]  = "hello world!";
	char *res;
	
	res = ft_strrev(one);
	printf("one: %s\n", one);
	printf("res: %s\n", res);
	return (0);
}


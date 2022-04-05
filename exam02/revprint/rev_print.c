# include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_rev_print(char *str)
{
	int i;
	i = ft_strlen(str);
	i--;
	while(0 <= i)
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, "\n", 1);
	return (str);
}

	
	/* not good!!!
char *ft_rev_print(char *str)
{
	int i = 0;
	char rstr[100];
	int j = 0;

	if (!str)
		return ("\n");
	while(str[i])
		i++;
	i--;
	while(i < 0)
		rstr[j++] = str[i--];
	return (rstr);
}
*/

int main(int argc, char **argv)
{
	char *str;
	(void)argc;
	str = ft_rev_print(argv[1]);
	return (0);
}

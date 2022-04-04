#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] <= 32 && argv[1][i])
			i++;
		while (argv[1][i] && argv[1][i] > 32)
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

/* last word?
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		iswhitespace(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_putstr(char *s)
{
	write (1, s, ft_strlen(s));
}

int main(int argc, char **argv)
{
	int i;
	
	if (argc == 2 && ft_strlen(argv[1]) > 0)
	{
		i = ft_strlen(argv[1]) - 1;
		while(iswhitespace(argv[1][i]))
			i--;
		while(!(iswhitespace(argv[1][i])) && i > 0)
			i--;
		if (iswhitespace(argv[1][i]))
			i++;
		while (!(iswhitespace(argv[1][i])) && argv[1][i] != '\0')
		{
			ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}

*/

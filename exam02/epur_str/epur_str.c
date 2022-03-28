#include <unistd.h>

int is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int ft_find_word(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (!is_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void ft_one_space(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!is_space(str[i]))
		{
			write(1, &str[i], 1);
			if (is_space(str[i + 1]) && 1 == ft_find_word(str, i + 2))
			{
				write(1, " ", 1);
				i++;
			}
			i++;
		}
		else 
			i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_one_space(argv[1]);
	write(1, "\n", 1);
	return (0);
}

#include <unistd.h>

int find_char(char c, char *b, int *j)
{
	while (b[*j])
	{
		if (b[(*j)++] == c)
			return (1);
	}
	return (0);
}

int hidenp(char *a, char *b)
{
	int i = 0;
	int j = 0;

	if (a == NULL || b == NULL)
		return (-1);
	while (a[i])
	{
		if (0 == find_char(a[i++], b, &j))
		{
			write(1, "0\n", 2);
			return (-1);
		}
	}
	write(1, "1\n", 2);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	hidenp(argv[1], argv[2]);
	return (0);
}

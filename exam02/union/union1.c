#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	x;
	int	flag;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			flag = 0;
			while (j < i)
			{
				if (argv[1][i] == argv[1][j++])
					flag = 1;
			}
			if (flag == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		j = 0;
		while (argv[2][j])
		{
			i = 0;
			flag = 0;
			while (argv[1][i])
			{
				if (argv[2][j] ==  argv[1][i++])
					flag = 1;
			}
			x = 0;
			while (x < j)
			{
				if (argv[2][j] == argv[2][x++])
					flag = 1;
			}
			if (flag == 0)
				write(1, &argv[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

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
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
					flag = 1;
				x = 0;
				while (x < i)
				{
					if (argv[1][i] == argv[1][x])
						flag = 1;
					x++;
				}
				j++;
				
			}
			if (flag == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

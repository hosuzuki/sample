#include <unistd.h>

int ft_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\v' || c == '\0' || c == '\f' || c == '\r' || c == '\n')
		return (0);
	return (-1);
}
/*
void print_char(char c)
{
	write(1, &c, 1);
}
*/
int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	char c;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (-1);
	}
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			c = argv[i][j];
			if (ft_space(argv[i][j + 1]) == 0 && 'a' <= c && c <= 'z')
				c -= 32;
				//				print_char(c - 32);
			else if (ft_space(argv[i][j + 1]) != 0 && 'A' <= c && c <= 'Z')
	//			print_char(c + 32);
		//	else 
				c += 32;
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
//	write(1, "\n", 1);
	return (0);
}

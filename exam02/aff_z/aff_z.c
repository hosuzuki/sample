#include <unistd.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	write(1, "z\n", 2);
	return (0);
}

	
	/*{
	int i = 0;
	
	if (argc != 2)
	{
		write(1, "z\n", 2);
		return (1);
	}
	if (!argv[1])
		return (1);
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == 'z')

			*/



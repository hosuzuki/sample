#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	int a;
	int b;
	int i = 1;
	int res = 0;
	
	if (argc != 3)
	{
		printf("\n");
		return (-1);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	while (i <= a && i <= b)
	{
		if (a % i == 0 && b % i == 0)
			res = i;
		i++;
	}
	printf("%d\n", res);
	return (0);
}


/*

int ft_find_deno(int a, int b)
{
	int i = 1;
	while (i <= b)
	{
		if (b % i == 0)
		{
			if (a  == b / i)
				return (0);
		}
		i++;
	}
	return (-1);
}

int main(int argc, char **argv)
{
	int a;
	int b;
	int i = 1;

	if (argc != 3)
		printf("\n");
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	while (i <= a)
	{
		if (a % i == 0)
		{
			if (0 == ft_find_deno(a / i, b))
			{
				printf("%d\n", a / i); 
				break;
			}
		}
		i++;
	}
	return (0);
}
*/

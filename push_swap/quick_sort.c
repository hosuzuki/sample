#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static int	partition(int *sort, size_t left, size_t right)
{
//	size_t	l;
	size_t	r;
	int		tmp;

//	l = left;
	r = right;
	while (left < r)
//	while (l < r)
	{
	//	while (sort[l] < sort[left] && l < right) // ???
		//	l++;
//		while (sort[r] >= sort[left] && r > left)
		while (sort[left] <= sort[r] && left < r)
			r--;
//		if (l >= r)
		if (left >= r)
			break;
//		tmp = sort[l];
//		sort[l] = sort[r];
//		sort[r] = tmp;
		tmp = sort[left];
		sort[left] = sort[r];
		sort[r] = tmp;
	}
//	if (l == left)
//		return (l + 1);
		return (left + 1);
//	return (l);
}

static void	quick_sort(int *sort, size_t left, size_t right)
{
	size_t part;

	if(left >= right)
		return ;
	part = partition(sort, left, right);
//	quick_sort(sort, left, part - 1);
	quick_sort(sort, part, right);
}

int main(int argc, char **argv)
{
/*	char *str;
	int buf[50];
	int i;
	int j;
	int x;

	i = 0;
	while(i < argc - 1)
	{
		x = 0;
		j = 0;
		str = argv[i + 1];
		while (isdigit(str[x]) != 0)
			j = j * 10 + (str[x++] - '0');
	else
			return (1);
		buf[i] = j;
	 	i++;
	}
//	buf[i - 1] = '\0';
*/

	int buf[50];
	int i;

	i = 0;
	while (i < argc - 1)
	{
		buf[i] = atoi(argv[i + 1]);
		if (buf[i++] == 0)
		{
			printf("Invalid Input\n");
			return (1);
		}
	}
	quick_sort(buf, 0, i - 1);
	for (int j = 0; j < argc - 1; j++)
		printf("%d ", buf[j]);
	printf("\n");
	return (0);
}

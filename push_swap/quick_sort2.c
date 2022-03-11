#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static void	swap(int *sort, size_t a, size_t b)
{
	int tmp;

	tmp = sort[a];
	sort[a] = sort[b];
	sort[b] = tmp;
}

static int	partition(int *sort, size_t left, size_t right)
{
	size_t	l;
	size_t	r;
	int		pivot;

	if (sort[left] < sort[left + 1])
		pivot = sort[left + 1];
	else
		pivot = sort[left];
	l = left;
	r = right;
	while (1)
	{
		while (l < right)
		{
			if (pivot <= sort[l])
				break;
			l++;
		}
		while (left < r)
		{
			if (sort[r] <= pivot)
				break;
			r--;
		}
		if (l >= r)
			break;
		swap(sort, l, r);
	}
	if (l == left)
		return (l + 1);
	return (l);
}

static void	quick_sort(int *sort, size_t left, size_t right)
{
	size_t part;

	if(left >= right)
		return ;
	part = partition(sort, left, right);
	quick_sort(sort, left, part - 1);
	quick_sort(sort, part, right);
}

static int	no_duplicate(int *buf, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (buf[j] == buf[i])
			return (1);
		j++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int buf[50];
	int i;

	i = 0;
	while (i < argc - 1)
	{
		buf[i] = atoi(argv[i + 1]);
		if (buf[i] == 0)
		{
			printf("Invalid Input\n");
			return (1);
		}
		else if (no_duplicate(buf, i) != 0)
		{
			printf("Dupicates are not allowed\n");
			return (1);
		}
		i++;
	}
	quick_sort(buf, 0, i - 1);
	for (int j = 0; j < argc - 1; j++)
		printf("%d ", buf[j]);
	printf("\n");
	return (0);
}

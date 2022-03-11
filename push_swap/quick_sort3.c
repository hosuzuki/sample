#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int cmp(const char *i, const char *j)
{
	int a = (int)i;
	int b = (int)j;
	if (a < b)
		return (-1);
	else if (a == b)
		return (0);
	else
		return (1);
}

void swap(void* x, void* y, size_t sz)
{
	char* a = x;
	char* b = y;
	while (sz > 0) 
	{
		char t = *a;
		*a++ = *b;
		*b++ = t;
		sz--;
	}
}

void* partition(void* a, int (*cmp)(void const*, void const*), size_t sz, size_t n)
{
	char* const base = a;
	if (n <= 1) return base + sz;
	char* lo = base;
	char* hi = &base[sz * (n - 1)];
	char* m  = lo + sz * ((hi - lo) / sz / 2);
	if (cmp(lo, m) > 0)
		swap(lo, m, sz);
	if (cmp(m, hi) > 0)
	{
		swap(m, hi, sz);
		if (cmp(lo, m) > 0)
			swap(lo, m, sz);
	}
	while (1)
	{
		while (cmp(lo, m) < 0) lo += sz;
		while (cmp(m, hi) < 0) hi -= sz;
		if (lo >= hi) return hi + sz;
		swap(lo, hi, sz);
		if (lo == m)
			m = hi;
		else if (hi == m)
			m = lo;
		lo += sz;
		hi -= sz;
	}
}

void quicksort(void* a, int (*cmp)(void const*, void const*), size_t sz, size_t n) 
{
	if (n <= 1) return;
	char* p = partition(a, cmp, sz, n);
	char* const base = a;
	size_t n_lo = (p - base) / sz;
	size_t n_hi = (&base[sz * n] - p) / sz;
	quicksort(a, cmp, sz, n_lo);
	quicksort(p, cmp, sz, n_hi);
}

int main(int argc, char **argv)
{
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
	quicksort(buf, cmp, 0, i - 1);
	for (int j = 0; j < argc - 1; j++)
		printf("%d ", buf[j]);
	printf("\n");
	return (0);
}

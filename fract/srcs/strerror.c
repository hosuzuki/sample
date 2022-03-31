#include <stdio.h>

int main(void)
{
	const char fname[] = "file.txt";
	FILE *fp;

	fp = fopen(fname, "r");
	if (fp == NULL) {
		perror(fname);
		return 1;
	}
	fclose(fp);
	return 0;
}
/*
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char fname[] = "file.txt";
	FILE *fp;

	fp = fopen(fname, "r");
	if (fp == NULL) {
		fprintf(stderr, "%s: %s\n", fname, strerror(errno));
		return 1;
	}
	fclose(fp);
	return 0;
}
*/

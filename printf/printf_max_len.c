#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int	fd;
	ssize_t rc;
	size_t len;
	char	buf[(size_t)INT_MAX + 10];

	fd = open("max_len_test", O_RDONLY);
	if (argc != 2)
	{
		printf("type buffer size after ./a.out\n");
		return (-1);
	}
	len = atoi(argv[1]);
	rc = read(fd, buf, len);
	if (rc == -1)
		return (-1);
	buf[rc] = '\0';
	printf("rc is %zu\n", rc);
	printf("BUFSIZ is: %d\n", BUFSIZ);
	printf("%s\n", buf);
	close (fd);
	return (0);
}

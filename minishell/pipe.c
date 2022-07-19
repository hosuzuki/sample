#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 1024

int main(int argc, char **argv)
{
	int         pipefd[2];
	int         p_id;
	int         status;
	FILE        *fp;
	char        buff[BUFF_SIZE];

	if (argc != 2) 
	{
		fprintf(stderr, "main : argc has to be 2\n");
		exit(EXIT_FAILURE);
	}

	if (pipe(pipefd) == -1)
	{
		perror("main");
		exit(EXIT_FAILURE);
	}

	if ((p_id = fork()) == -1)
	{
		perror("main");
		exit(EXIT_FAILURE);
	}

	if (p_id == 0)
	{
		/* 子プロセス */
		/* 使用しないwrite側はクローズ */
		close(pipefd[1]);
		/* パイプから読み込む */
		while (read(pipefd[0], &buff, BUFF_SIZE) > 0) 
		{
			fputs(buff, stdout);
		}
		close(pipefd[0]);
	}
	else
	{
		/* 親プロセス */
		/* 使用しないread側はクローズ */
		close(pipefd[0]);
		if ((fp = fopen(*(argv + 1), "r")) != NULL)
		{
			while(fgets(buff, BUFF_SIZE, fp) != NULL)
			{
				/* パイプに書き込む */
				write(pipefd[1], buff, strlen(buff) + 1);
			}
			fclose(fp);
		}
		else
		{
			perror("親プロセス");
		}
		close(pipefd[1]);
		wait(&status);
	}
	return EXIT_SUCCESS;
}

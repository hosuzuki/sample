#include <stdio.h>
#include <stdlib.h>

/*
 *  * getenvの使い方サンプル
 *   */
int main(int argc, char *argv[]) {
	char *envp = getenv("DEBUG");
	int debug = 0;

	if (envp != NULL)
	{
		fprintf(stdout, "DEBUG[%s]\n", envp);
		debug = 1;
	}
	if (debug)
	{
	// debug = 1の時だけ
	fprintf(stdout, "DEBUG:%s\n", "<<<debug start>>>");
	}
	fprintf(stdout, "getenv sample program!\n");
	if (debug)
	{
	//               // debug = 1の時だけ
	fprintf(stdout, "DEBUG:%s\n", "<<<program end>>>");
	}
	return 0;
}


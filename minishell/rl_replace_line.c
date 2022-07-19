#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>

void handler (int status)
{
//	printf("line_buffer: %d\n", get_line_buffer());
//	printf("\nline_buffer: %s\n", rl_line_buffer);
	putchar('\n');
	rl_replace_line("",0);
//	printf("\nline_buffer: %s\n", rl_line_buffer);
	rl_on_new_line();
	rl_redisplay();
//	rl_done = 1;
//	printf("\n");
	exit(0);
}

int main (int argc, char** argv)
{
	char* entry;
	while (1)
	{
		signal(SIGINT,handler);
		signal(SIGQUIT, SIG_IGN);
		entry = readline("mini> ");
	}
	printf("\nEntry was: %s\n", entry);
	return 0;
}

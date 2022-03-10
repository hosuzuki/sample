#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Cmd_tag {
	ADD,
	SUBSTRUCT,
	EXIT,
	NUM,
};

enum Ret_tag {
	CONTI,
	OUT,
};

static const char* const CMD_STR[NUM] = {
	"a",
	"s",
	"e"
};

enum Ret_tag cmd_add(void);
enum Ret_tag cmd_substruct(void);
enum Ret_tag cmd_exit(void);

typedef enum Ret_tag (*cmd_func)(void);
static const cmd_func CMD_FUNC[NUM] = {
	cmd_add,
	cmd_substruct,
	cmd_exit
};

static int number;

void print_instruction(void)
{
	puts("enter a command" );
	printf( "add 1      : %s\n", CMD_STR[ADD]);
	printf( "substruct 1: %s\n", CMD_STR[SUBSTRUCT]);
	printf( "exit       : %s\n", CMD_STR[EXIT]);
}

void get_line(char* buf, size_t size)
{
	fgets(buf, size, stdin);
	char* p = strchr(buf, '\n');
	if (p != NULL)
		*p = '\0';
	//printf("buf : %s\n", buf);
}

enum Ret_tag get_cmd(void)
{
	char buf[20];
	int i;

	get_line(buf, sizeof(buf));
	enum Cmd_tag cmd = NUM;
	i = 0;
	while(i < NUM)
	{
		if(strcmp(buf, CMD_STR[i]) == 0)
		{
			cmd = i;
			break ;
		}
		i++;
	}
	//printf("cmd : %d\n", cmd);
	if (0 <= cmd && cmd < NUM)
		return (CMD_FUNC[cmd]());
	else
		return (CONTI);
}

enum Ret_tag cmd_add(void)
{
	number++;
	printf("\nnumber is %d\n\n", number);
	return (CONTI);
}

enum Ret_tag cmd_substruct(void)
{
	number--;
	printf("\nnumber is %d\n\n", number);
	return (CONTI);
}

enum Ret_tag cmd_exit(void)
{
	printf("Exit.\n");
	return (OUT);
}

int main(void)
{
	puts( "initial number is 0.");
	print_instruction();
	while (1)
	{
		puts("enter a command" );
		if(get_cmd() == OUT)
			break;
	}
	return (0);
}

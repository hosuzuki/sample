#include "dcll.h"

int main(void)
{
	init_head();
	while(1)
	{
		print_explain();
		if(get_cmd() == CMD_RET_VALUE_EXIT) // CMD_RET_VALUE_EXIT = 1
			break;
		puts( "" );
	}
	return 0;
}

void init_head(void)
{
	gHead.value = 0;
	gHead.next = &gHead;
	gHead.prev = &gHead;
}

void print_explain(void)
{
	puts( "Enter a command" );
	printf( " add a value: %s (%s)\n", CMD_STR[CMD_ADD][CMD_STR_SHORT], CMD_STR[CMD_ADD][CMD_STR_LONG] );
	printf( " delete a value: %s (%s)\n", CMD_STR[CMD_DELETE][CMD_STR_SHORT], CMD_STR[CMD_DELETE][CMD_STR_LONG] );
	printf( " search a value: %s (%s)\n", CMD_STR[CMD_SEARCH][CMD_STR_SHORT], CMD_STR[CMD_SEARCH][CMD_STR_LONG] );
	printf( " empty the list: %s (%s)\n", CMD_STR[CMD_CLEAR][CMD_STR_SHORT], CMD_STR[CMD_CLEAR][CMD_STR_LONG] );
	printf( " print out value in the list: %s (%s)\n", CMD_STR[CMD_PRINT][CMD_STR_SHORT], CMD_STR[CMD_PRINT][CMD_STR_LONG] );
	printf( " exit: %s(%s)\n", CMD_STR[CMD_EXIT][CMD_STR_SHORT], CMD_STR[CMD_EXIT][CMD_STR_LONG] );
	puts( "" );
}

enum CmdRetValue_tag get_cmd(void)
{
	char buf[20];
	get_line( buf, sizeof(buf) );

	enum Cmd_tag cmd = CMD_NUM; //cmd = 6
	for(int i = 0; i < CMD_NUM; ++i )
	{
		if(strcmp(buf, CMD_STR[i][CMD_STR_SHORT]) == 0
				|| strcmp( buf, CMD_STR[i][CMD_STR_LONG]) == 0)
		{
			cmd = i;
			break;
		}
	}
	if( 0 <= cmd && cmd < CMD_NUM )
		return CMD_FUNC[cmd]();
	else
		puts( "the command isn't valid" );
	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_add(void)
{
	char buf[40];
	int value;

	puts( "Enter the value to be added" );
	fgets(buf, sizeof(buf), stdin );
	sscanf(buf, "%d", &value);
	add_elem(value);
	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_delete(void)
{
	char buf[40];
	int value;

	puts( "Enter the value to be deleted");
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d", &value);
	if(delete_elem(value) >= 1){
		puts( "deleted" );
	}
	else{
		puts("cannot find the value");
	}
	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_search(void)
{
	char buf[40];
	int value;

	puts("Enter the vlue to be searched");
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d", &value);
	if(search_elem(value) == NULL )
		printf( "%d doesn't exist.\n", value );
	else
		printf( "%d exits.\n", value );
	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_clear(void)
{
	clear_list();
	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_print(void)
{
	print_list();
	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_exit(void)
{
	puts( "Exit" );
	return CMD_RET_VALUE_EXIT;
}

void add_elem(int value)
{
	struct LinkedList_tag	*tail = search_tail();
	struct LinkedList_tag	*elem = malloc( sizeof(struct LinkedList_tag) );
	if( elem == NULL )
	{
		fputs( "malloc error", stderr);
		exit (1);
	}
	elem->value = value;
	elem->next = &gHead;
	elem->prev = tail;
	tail->next = elem;
}

int delete_elem(int value)
{
	struct LinkedList_tag* p = gHead.next;
	int count = 0;

	while(p != &gHead)
	{
		if(p->value == value)
		{
			p = delete_one_node(p);
			++count;
		}
		else
			p = p->next;
	}
	return count;
}

void clear_list(void)
{
	struct LinkedList_tag* p = gHead.next;

	while( p != &gHead )
		p = delete_one_node(p);
}

void print_list(void)
{
	struct LinkedList_tag* p = gHead.next;

	if(p == &gHead)
	{
		puts("The list is empty.");
		return;
	}
	while(p != &gHead)
	{
		printf("%d\n", p->value);
		p = p->next;
	}
}

struct LinkedList_tag	*search_tail(void)
{
	struct LinkedList_tag	*p = &gHead;

	while(p->next != &gHead)
		p = p->next;
	return p;
}

struct LinkedList_tag	*search_elem(int value)
{
	struct LinkedList_tag	*p = gHead.next;

	while( p != &gHead ){
		if( p->value == value ){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

struct LinkedList_tag* delete_one_node(struct LinkedList_tag* node)
{
	struct LinkedList_tag* const prev = node->prev;
	node->next->prev = prev;
	prev->next = node->next;
	free(node);
	return prev->next;
}

void get_line(char* buf, size_t size)
{
	fgets(buf, size, stdin);

	char* p = strchr(buf, '\n');
	if (p != NULL)
		*p = '\0';
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Cmd_tag {
	CMD_ADD,
	CMD_DELETE,
	CMD_SEARCH,
	CMD_CLEAR,
	CMD_PRINT,
	CMD_EXIT,
	CMD_NUM
};

enum CmdStr_tag {
	CMD_STR_SHORT,
	CMD_STR_LONG,
	CMD_STR_NUM
};

enum CmdRetValue_tag {
	CMD_RET_VALUE_CONTINUE,
	CMD_RET_VALUE_EXIT,
};

static const char* const CMD_STR[CMD_NUM][CMD_STR_NUM] = {
	{ "a", "add" },
	{ "d", "delete" },
	{ "s", "search" },
	{ "c", "clear" },
	{ "p", "print" },
	{ "e", "exit" }
};

static void init_head(void);
static void print_explain(void);
static void print_blank_lines(void);
static enum CmdRetValue_tag get_cmd(void);
static enum CmdRetValue_tag cmd_add(void);
static enum CmdRetValue_tag cmd_delete(void);
static enum CmdRetValue_tag cmd_search(void);
static enum CmdRetValue_tag cmd_clear(void);
static enum CmdRetValue_tag cmd_print(void);
static enum CmdRetValue_tag cmd_exit(void);
static void add_elem(int value);
static int delete_elem(int value);
static void clear_list(void);
static void print_list(void);
static struct LinkedList_tag* search_tail(void);
static struct LinkedList_tag* search_elem(int value);
static struct LinkedList_tag* delete_one_node(struct LinkedList_tag* node);
static void get_line(char* buf, size_t size);

typedef enum CmdRetValue_tag (*cmd_func)(void);
static const cmd_func CMD_FUNC[CMD_NUM] = {
	cmd_add,
	cmd_delete,
	cmd_search,
	cmd_clear,
	cmd_print,
	cmd_exit
};

struct LinkedList_tag {
	int                         value;
	struct LinkedList_tag*      next;
	struct LinkedList_tag*      prev;
};

static struct LinkedList_tag gHead;  // 先頭の要素


int main(void)
{
	init_head();
	while(1)
	{
		print_explain();
		if( get_cmd() == CMD_RET_VALUE_EXIT ){
			break;
		}
		print_blank_lines();
	}
	return 0;
}

void init_head(void)
{
	gHead.value = 0;
	gHead.next = &gHead;  // 循環するので nextポインタは自分自身を指す
	gHead.prev = &gHead;  // 循環するので prevポインタは自分自身を指す
}

void print_explain(void)
{
	puts( "コマンドを入力してください。" );
	printf( "　連結リストに要素を追加する: %s (%s)\n", CMD_STR[CMD_ADD][CMD_STR_SHORT], CMD_STR[CMD_ADD][CMD_STR_LONG] );
	printf( "　連結リストから要素を削除する: %s (%s)\n", CMD_STR[CMD_DELETE][CMD_STR_SHORT], CMD_STR[CMD_DELETE][CMD_STR_LONG] );
	printf( "　連結リストから要素を探す: %s (%s)\n", CMD_STR[CMD_SEARCH][CMD_STR_SHORT], CMD_STR[CMD_SEARCH][CMD_STR_LONG] );
	printf( "　連結リストを空にする: %s (%s)\n", CMD_STR[CMD_CLEAR][CMD_STR_SHORT], CMD_STR[CMD_CLEAR][CMD_STR_LONG] );
	printf( "　連結リストの中身を出力する: %s (%s)\n", CMD_STR[CMD_PRINT][CMD_STR_SHORT], CMD_STR[CMD_PRINT][CMD_STR_LONG] );
	printf( "　終了する: %s(%s)\n", CMD_STR[CMD_EXIT][CMD_STR_SHORT], CMD_STR[CMD_EXIT][CMD_STR_LONG] );
	puts( "" );
}

void print_blank_lines(void)
{
	puts( "" );
	puts( "" );
}

enum CmdRetValue_tag get_cmd(void)
{
	char buf[20];
	get_line( buf, sizeof(buf) );

	enum Cmd_tag cmd = CMD_NUM;
	for( int i = 0; i < CMD_NUM; ++i ){
		if( strcmp( buf, CMD_STR[i][CMD_STR_SHORT] ) == 0
				|| strcmp( buf, CMD_STR[i][CMD_STR_LONG] ) == 0
			){
			cmd = i;
			break;
		}
	}

	if( 0 <= cmd && cmd < CMD_NUM ){
		return CMD_FUNC[cmd]();
	}
	else{
		puts( "そのコマンドは存在しません。" );
	}

	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_add(void)
{
	char buf[40];
	int value;

	puts( "追加する数値データを入力してください。" );
	fgets( buf, sizeof(buf), stdin );
	sscanf( buf, "%d", &value );

	add_elem( value );

	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_delete(void)
{
	char buf[40];
	int value;

	puts( "削除する数値データを入力してください。" );
	fgets( buf, sizeof(buf), stdin );
	sscanf( buf, "%d", &value );

	if( delete_elem(value) >= 1 ){
		puts( "要素を削除しました。" );
	}
	else{
		puts( "削除する要素は見つかりませんでした。" );
	}

	return CMD_RET_VALUE_CONTINUE;
}

enum CmdRetValue_tag cmd_search(void)
{
	char buf[40];
	int value;

	puts( "探索する数値データを入力してください。" );
	fgets( buf, sizeof(buf), stdin );
	sscanf( buf, "%d", &value );

	if( search_elem(value) == NULL ){
		printf( "%d は連結リスト中に存在しません。\n", value );
	}
	else{
		printf( "%d は連結リスト中に存在します。\n", value );
	}
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
	puts( "終了します。" );
	return CMD_RET_VALUE_EXIT;
}

void add_elem(int value)
{
	struct LinkedList_tag* tail = search_tail();
	struct LinkedList_tag* elem = malloc( sizeof(struct LinkedList_tag) );
	if( elem == NULL ){
		fputs( "メモリ割り当てに失敗しました。", stderr );
		exit( 1 );
	}
	elem->value = value;
	elem->next = &gHead; // 末尾に追加するので、次の要素は先頭
	elem->prev = tail;   // 末尾に追加するので、前の要素はこれまでに末尾だった要素
	tail->next = elem;
}

int delete_elem(int value)
{
	struct LinkedList_tag* p = gHead.next;
	int count = 0;

	while( p != &gHead ){
		if( p->value == value ){
			p = delete_one_node( p );
			++count;
		}
		else{
			p = p->next;
		}
	}
	return count;
}

void clear_list(void)
{
	struct LinkedList_tag* p = gHead.next;

	while( p != &gHead ){
		p = delete_one_node( p );
	}
}

void print_list(void)
{
	struct LinkedList_tag* p = gHead.next;

	if( p == &gHead ){
		puts( "リストは空です。" );
		return;
	}
	while( p != &gHead ){
		printf( "%d\n", p->value );
		p = p->next;
	}
}

struct LinkedList_tag* search_tail(void)
{
	struct LinkedList_tag* p = &gHead;

	while( p->next != &gHead ){
		p = p->next;
	}
	return p;
}

struct LinkedList_tag* search_elem(int value)
{
	struct LinkedList_tag* p = gHead.next;

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
	free( node );
	return prev->next;
}

void get_line(char* buf, size_t size)
{
	fgets(buf, size, stdin);

	char* p = strchr(buf, '\n');
	if (p != NULL) {
		*p = '\0';
	}
}
#ifndef DCLL_H
# define DCLL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

enum Cmd_tag {
	CMD_ADD, // 0
	CMD_DELETE, //1
	CMD_SEARCH,
	CMD_CLEAR,
	CMD_PRINT,
	CMD_EXIT,
	CMD_NUM // 6
};

enum CmdStr_tag {
	CMD_STR_SHORT,
	CMD_STR_LONG,
	CMD_STR_NUM // 2
};

enum CmdRetValue_tag {
	CMD_RET_VALUE_CONTINUE,
	CMD_RET_VALUE_EXIT,
};

static const char* const CMD_STR[CMD_NUM][CMD_STR_NUM] = {// CMD_STR[6][2]
	{ "a", "add" }, // CMD_STR[0][0], CMD_STR[0][1]
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

typedef enum CmdRetValue_tag (*cmd_func)(void); // ???
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

static struct LinkedList_tag gHead;

#endif

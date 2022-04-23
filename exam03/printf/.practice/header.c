#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_lst
{
	va_list args;
	//long	len;
	size_t len;
	//forgot!
	int status;
	int	sign;
	int	pre_flag;
	long long pre;
	long long wid;
} t_lst;
// forgot t_lst

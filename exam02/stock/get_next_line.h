#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//# define GOOD 1
//# define ERROR -1
//# define END 0
//# define BUFSIZE 1024

typedef struct s_lst
{
//	int				fd;
	char	*str;
	int	len;
//	struct s_stock	*next;
}	t_lst;

int	get_next_line(char **line);

#endif

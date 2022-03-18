#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define GOOD 1
# define ERROR -1
# define END 0

typedef struct s_stock
{
//	int				fd;
	char	*str;
	int	len;
	struct s_stock	*next;
}	t_stock;

int	get_next_line(char **line);

#endif

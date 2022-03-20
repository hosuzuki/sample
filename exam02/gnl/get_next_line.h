#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int	get_next_line(char **line);
char	*ft_strchar(char *str, int c);
char	*ft_strjoin(char	*buf, char *b);
char	*ft_strndup(char *str, size_t len);
size_t ft_strlen(char	*str);

#endif

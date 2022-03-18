#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
	{
		free ((void *)s2);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free ((void *)s2);
	return (dst);
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

t_node	*ft_lstnew(int fd, void	*content)
{
	t_node	*buf_lst;

	buf_lst = (t_node *)malloc(sizeof(t_node));
	if (!buf_lst)
		return (NULL);
	buf_lst->fd = fd;
	buf_lst->str = ft_strndup(content, 0);
	if (!buf_lst->str)
	{
		free(buf_lst);
		return (NULL);
	}
	buf_lst->next = NULL;
	return (buf_lst);
}

static void	ft_free_lst(t_node **holder, t_node *buf_lst)
{
	t_node	*tmp;

	if (!holder || !(*holder))
		return ;
	if (*holder == buf_lst)
		*holder = buf_lst->next;
	else
	{
		tmp = *holder;
		while (tmp && tmp->next != buf_lst)
			tmp = tmp->next;
		tmp->next = buf_lst->next;
	}
	free (buf_lst->str);
	free (buf_lst);
	return ;
}

static char	*ft_create_ret(t_node *buf_lst)
{
	char	*ret;
	char	*isnewl;
	char	*tmp;

	isnewl = ft_strchr(buf_lst->str, '\n');
	if (!isnewl)
	{
		if (*(buf_lst->str) == '\0')
			return (NULL);
		ret = ft_strndup(buf_lst->str, ft_strlen(buf_lst->str));
	}
	else
	{
		ret = ft_strndup(buf_lst->str, isnewl - buf_lst->str + 1);
		tmp = ft_strndup(isnewl + 1, ft_strlen(isnewl + 1));
		if (!tmp)
		{
			free (ret);
			return (NULL);
		}
		free (buf_lst->str);
		buf_lst->str = tmp;
	}
	return (ret);
}

static int	ft_read(int fd, t_node *buf_lst)
{
	ssize_t	rc;
	char	*buf;

	while (1)
	{
		buf = NULL;
		if (ft_strchr(buf_lst->str, '\n'))
			return (GOOD);
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1 || rc == 0)
		{
			free(buf);
			if (rc == -1)
				return (ERROR);
			return (END);
		}
		buf[rc] = '\0';
		buf = ft_strjoin(buf_lst->str, buf);
		if (!buf)
			return (ERROR);
		free (buf_lst->str);
		buf_lst->str = buf;
	}
}

static t_node	*ft_create_lst(char **line, t_node **holder)
{
	t_node	*buf_lst;

	if (!(*holder))
	{
		buf_lst = ft_lstnew(fd, "");
		*holder = buf_lst;
		return (buf_lst);
	}
	buf_lst = *holder;
	while (buf_lst)
	{
		if (buf_lst->fd == fd)
			return (buf_lst);
		buf_lst = buf_lst->next;
	}
	buf_lst = ft_lstnew(fd, "");
	if (!buf_lst)
		return (buf_lst);
	buf_lst->next = *holder;
	*holder = buf_lst;
	return (buf_lst);
}
char	*init_str(char **line)
{
	
t_stock	*init_stock(void)
{
	t_stock	*stock;
	
	stock = (t_stock *)malloc(sizeof(t_stock));
	(!stock)
		return (NULL);
	stock->str = NULL;
	stock->len = 0;
	stock->next = NULL;
	return (stock);
}

//char	*get_next_line(int fd)
int	get_next_line(char **line)
{
	static t_stock	*stock;
	t_node			*buf;
	int				ret;

	stock = init_stock();
	stock->str = init_str(line);
	
	buf = ft_create_lst(line, &holder);
	if (!buf_lst)
		return (NULL);
	status = ft_read(fd, buf_lst);
	if (status == ERROR)
	{
		free_all(&holder, buf_lst);
		return (-1);
	}
	ret = ft_create_ret(buf_lst);
	if (status == END || ret == NULL)
		ft_free_lst(&holder, buf_lst);
	return (ret);
}

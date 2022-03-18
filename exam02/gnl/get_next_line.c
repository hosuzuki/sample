#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	free_all(t_lst *head)
{
	t_lst	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->str)
			free (str);
		free (head);
		head = tmp;
	}
}

static char	*ft_create_ret(t_lst *buf)
{
	char	*ret;
	char	*isnewl;
	char	*tmp;

	isnewl = ft_strchr(buf->str, '\n');
	if (!isnewl)
	{
		if (*(buf->str) == '\0')
			return (NULL);
		ret = ft_strndup(buf->str, ft_strlen(buf->str));
	}
	else
	{
		ret = ft_strndup(buf->str, isnewl - buf->str + 1);
		tmp = ft_strndup(isnewl + 1, ft_strlen(isnewl + 1));
		if (!tmp)
		{
			free (ret);
			return (NULL);
		}
		free (buf->str);
		buf->str = tmp;
	}
	return (ret);
}

static int	ft_read(int fd, t_lst *buf)
{
	ssize_t	rc;
	char	*buf;

	while (1)
	{
		buf = NULL;
		if (ft_strchr(buf->str, '\n'))
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
		buf = ft_strjoin(buf->str, buf);
		if (!buf)
			return (ERROR);
		free (buf->str);
		buf->str = buf;
	}
}

t_lst	*ft_lstnew(void	*content)
{
	t_lst	*buf;

	buf = (t_lst *)malloc(sizeof(t_lst));
	if (!buf)
		return (NULL);
	buf->str = ft_strndup(content, 0);
	if (!buf->str)
	{
		free(buf);
		return (NULL);
	}
	buf->len = 0;
	buf->next = NULL;
	return (buf);
}

int	init_lst(char **line, t_lst *head)
{
	t_lst	*buf;
	t_lst	*tmp;

	if (!(*head))
	{
		buf = ft_lstnew("");
		if (!buf)
			return (-1);
		head = buf;
		return (0);
	}
	buf = ft_lstnew("");
	if (!buf)
	{
		free_all(head);
		return (-1);
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = buf;
	return (0);
//	buf->next = *head;
//	*head = buf;
//	return (buf);
}

char	*init_str(char **line)
{
	
t_lst	*init_lst(void)
{
	t_lst	*lst;
	
	lst = (t_lst *)malloc(sizeof(t_lst));
	(!lst)
		return (NULL);
	lst->str = NULL;
	lst->len = 0;
	lst->next = NULL;
	return (lst);
}

//char	*get_next_line(int fd)
int	get_next_line(char **line)
{
	static t_lst	*head;
	t_lst			*buf;
	int				ret;

	if (!head)
		head = NULL;
//	init_lst();
//	lst->str = init_str(line);
	
	if (-1 = init_lst(line, head);
		return (-1);
	status = ft_read(fd, buf);
	if (status == ERROR)
	{
		free_all(&head, buf);
		return (-1);
	}
	ret = ft_create_ret(buf);
	if (status == END || ret == NULL)
		ft_free_lst(&head, buf);
	return (ret);
}

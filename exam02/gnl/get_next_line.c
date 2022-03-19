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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup(char *s, size_t len)
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

void	free_all(t_lst *lst, char *str)
{
	if (lst)
	{
		if (lst->str)
			free (lst->str);
		free (lst);
	}
	if (str)
		free (str);
}

static char	*create_ret(t_lst *lst)
{
	char	*ret;
	char	*newl;
	char	*tmp;

	newl = ft_strchr(lst->str, '\n');
	if (!newl)
	{
		if (*(lst->str) == '\0')
			return (NULL);
		ret = ft_strndup(lst->str, ft_strlen(lst->str));
	}
	else
	{
		ret = ft_strndup(lst->str, newl - lst->str + 1);
		tmp = ft_strndup(newl + 1, ft_strlen(newl + 1));
		if (!tmp)
		{
			free (ret);
			return (NULL);
		}
		free (lst->str);
		lst->str = tmp;
	}
	return (ret);
}

static int	ft_read(t_lst *lst)
{
	ssize_t	rc;
	char	*new;
	char	*tmp;

	while (1)
	{
		tmp = NULL;
		if (ft_strchr(lst->str, '\n'))
			return (1);
		tmp = (char *)malloc(sizeof(char) * 1025);
		rc = read(0, tmp, 1024);
		if (rc == -1 || rc == 0)
		{
			free_all(lst, tmp);
			if (rc == -1)
				return (-1);
			return (0);
		}
		tmp[rc] = '\0';
		new = ft_strjoin(lst->str, tmp);
		if (!new)
		{
			free_all(lst, tmp);
			return (-1);
		}
		free (lst->str);
		free (tmp);
		lst->str = new;
	}
}

t_lst	*init_lst(void)
{
	t_lst	*lst;
	
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->str = NULL;
	lst->len = 0;
	return (lst);
}

int	get_next_line(char **line)
{
	static t_lst	*lst = NULL;
	int 	status;

	if(!lst)
	{
		lst = init_lst();
		if (!lst)
			return (-1);
	}
	status = ft_read(lst);
	if (status == -1)
	{
		free_all(lst, NULL);
		return (-1);
	}
	*line  = create_ret(lst);
	if (status == 0 || *line == NULL)
		free_all(lst, NULL);
	return (status);
}

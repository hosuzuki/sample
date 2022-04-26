#include "get_next_line.h"

size_t ft_strlen(char *s)
{
	size_t i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char *ft_strchr(char *s, int c)
{
	size_t i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}

char *ft_strndup(char *s, int len)
{
	size_t i = 0;
	char *res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (s)
	{
		while (s[i])
		{
			res[i] = s[i];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t i = 0;
	size_t j = 0;
	char *res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j])
			res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);
}

char	*ft_create_ret(char	**buf)
{
	char *new;
	char *ret;
	char *tmp;
	
	new = ft_strchr(*buf, '\n');
	if (!new)
	{
		if (*buf[0] == '\0')
			return (NULL);
		ret = ft_strndup(*buf, ft_strlen(*buf));
		if (!ret)
		{
			free (*buf);
			return (NULL);
		}
	}
	else
	{
		ret = ft_strndup(*buf, new - *buf);
		if (!ret)
		{
			free (*buf);
			return (NULL);
		}
		tmp = ft_strndup(new + 1, ft_strlen(new + 1));
		if (!tmp)
		{
			free (*buf);
			free (ret);
			return (NULL);
		}
		free (*buf);
		*buf = tmp;
	}
	return (ret);
}


int ft_read(char **buf)
{
	ssize_t rc;
	char	*b;
	char	*tmp;

	while (1)
	{
		if (*buf)
			if (0 != ft_strchr(*buf, '\n'))
				return (1);
		b = (char *)malloc(sizeof(char) * 1024 + 1);
		if (!b)
		{
			free(*buf);
			return (-1);
		}
		rc = read(0, b, 1024);
		if (rc == -1)
		{
			free (b);
		//	free (*buf);
			return (-1);
		}
		else if (rc == 0)
		{
			free (b);
			return (0);
		}
		b[rc] = '\0';
		tmp = ft_strjoin(*buf, b);
		free (*buf);
		free (b);
		if(!tmp)
			return (-1);
		*buf = tmp;
	}
}

int get_next_line(char **line)
{
	static char	*buf;
	int	status;

//	buf = ft_strndup("", 0);
//	buf = NULL;
//	if (!buf)
//		return (-1);
	status = ft_read(&buf);
	if (status == -1)
	{
		free(buf);
		return (-1);
	}
	if (buf != NULL)
		*line = ft_create_ret(&buf);
	if (status == 0 && *line == NULL)
	{
		*line = ft_strndup("", 0);
		if (!*line)
		{
			free (buf);
			return (-1);
		}
		free (buf);
		return (0);
	}
	return (status);
}


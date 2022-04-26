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
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char *ft_strndup(char *s, size_t len)
{
	size_t i = 0;
	char *res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (s)
	{
		while (i < len)
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

char *ft_create_ret(char **buf)
{
	char *new;
	char *tmp;
	char *res;

	new = ft_strchr(*buf, '\n');
	if (!new)
	{
		if (*buf[0] == '\0')
			return (NULL);
		else
		{
			res = ft_strndup(*buf, ft_strlen(*buf));
			if (!res)
			{
				free(*buf);
				return (NULL);
			}
		}
	}
	else
	{
		res = ft_strndup(*buf, new - *buf);
		if (!res)
		{
			free(*buf);
			return (NULL);
		}
		tmp = ft_strndup(new + 1, ft_strlen(new + 1));
		if (!tmp)
 		{
			free(*buf);
			free(res);
			return (NULL);
		}
		free (*buf);
		*buf = tmp;
	}
	return (res);
}

int ft_read(char **buf)
{
	char *tmp1;
	char *tmp2;
	ssize_t rc;

	while (1)
	{
		if (*buf)
			if (ft_strchr(*buf, '\n'))
				return (1);
		tmp1 = (char *)malloc(sizeof(char) * 1025);
		if (!tmp1)
			return (-1);
		rc = read(0, tmp1, 1024);
		if (rc == -1)
		{
			free (tmp1);
			return (-1);
		}
		if (rc == 0)
		{
			free (tmp1);
			return (0);
		}
		tmp1[rc] = '\0';
		tmp2 = ft_strjoin(*buf, tmp1);
		free (*buf);
		*buf = NULL;
		free (tmp1);
		if (!tmp2)
			return (-1);
		*buf = tmp2;
	}
}

int get_next_line(char **line)
{
	static char *buf;
	int res;
	
	res = ft_read(&buf);
	if (res == -1)
	{
		if (buf)
			free (buf);
		return (-1);
	}
	if (buf)
	{
		*line = ft_create_ret(&buf);
		if (!*line)
		{
			if (buf)
				free(buf);
			buf = NULL;
		}
	}
	if (res == 0 && *line == NULL)
	{
		*line = ft_strndup("", 0);
		if (!*line)
		{
			free (buf);
			return (-1);
		}
		free(buf);
		return (0);
	}
	return (res);
}

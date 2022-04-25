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
	return (NULL);
}

char *ft_strndup(char *s, int len)
{
	size_t i = 0;
	char *res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *ret;
	int i = 0;
	int j = 0;

	if (!s1 && !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}

int ft_create_ret(char **line, char *buf)
{
	char *new;
	char *tmp;

	new = ft_strchr(buf, '\n');
	if (!new)
	{
		*line = ft_strndup(buf, ft_strlen(buf));
		if (!(*line))
			return (-1);
	}
	else
	{
		*line = ft_strndup(buf, new - buf);
		if (!(*line))
			return (-1);
		tmp = ft_strndup(new + 1, ft_strlen(new + 1));
		if (!tmp)
		{
			free (*line);
			return (-1);
		}
	}
	return (0);
}

int ft_read(char **line, char *buf)
{
	char *str;
	char *tmp;
	int rc;

	(void)line;
	while (1)
	{
		if (ft_strchr(buf, '\n'))
			return (1);
		tmp = (char *)malloc(sizeof(char) * 1025); 
		if (!str)
			return (-1);
//		rc = read(0, 1024, str);
		rc = read(0, str, 1024);
		if (rc == -1)
		{
			free (str);
			return (-1);
		}
		if (rc == 0)
		{
			free (str);
			return (0);
		}
		tmp[rc] = '\0';
		str = ft_strjoin(buf, tmp);
		free (tmp);
		free (buf);
		if (!str)
			return (-1);
		buf = str;
	}
}

int get_next_line(char **line)
{
	static char *buf;
	int ret = 0;

	buf = (char *)malloc(sizeof(char));
	if(!buf)
		return (-1);
	buf = NULL;;
	ret = ft_read(line, buf);
	if (ret == 1 || ret == 0)
	 	ft_create_ret(line, buf);
	return (ret);
}

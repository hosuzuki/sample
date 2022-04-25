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
//forgot
	if (s[i] == (char)c)
			return (&s[i]);
	return (NULL);
}

//char *ft_strndup(char *s, int len)
char *ft_strndup(char *s, size_t len)
{
	size_t i = 0;
	char *res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
//	while (s[i])
	while (i < len)
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

//	if (!s1 && !s2)
//		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	//forogt
	if (s1)
	{
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
	}
	//forgot
	if (s2)
	{
		while (s2[j])
			ret[i++] = s2[j++];
	}
	ret[i] = '\0';
	return (ret);
}
/*
//int ft_create_ret(char **line, char *buf)
char *ft_create_ret(char **buf)
{
	char *new;
	char *tmp;
	//forgot
	char *ret;

	new = ft_strchr(*buf, '\n');
	if (!new)
	{
		//forgot
		if (*buf[0] == '\0')
			return (NULL);
		ret = ft_strndup(*buf, ft_strlen(*buf));
//		if (!(*line))
		if (!ret)
		{
			free(*buf);
			//return (-1);
			return (NULL);
		}
	}
	else
	{
//		*line = ft_strndup(buf, new - buf);
		ret = ft_strndup(*buf, new - *buf);
		//if (!(*line))
		if (!ret)
		{
			free (*buf);
			return (NULL);
		}
		tmp = ft_strndup(new + 1, ft_strlen(new + 1));
		if (!tmp)
		{
//			free (*line);
			free (*buf);
			free (ret);
			return (NULL);
		}
		//forgot
		free (*buf)
		*buf = tmp;
	}
	// mistook as 0
	return (ret);
}
*/

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

//int ft_read(char **line, char *buf)
int ft_read(char **buf)
{
	char *str;
	char *tmp;
//	int rc;
	ssize_t rc;

//	(void)line;
	while (1)
	{
		//forgot
		if (*buf)
		{
			if (ft_strchr(*buf, '\n'))
				return (1);
		}
		tmp = (char *)malloc(sizeof(char) * 1025); 
		if (!tmp)
		{
			//forgot
			free (*buf);
			return (-1);
		}
//		rc = read(0, 1024, str);
		rc = read(0, tmp, 1024);
		if (rc == -1)
		{
			free (tmp);
			return (-1);
		}
		if (rc == 0)
		{
			free (tmp);
			return (0);
		}
		tmp[rc] = '\0';
		str = ft_strjoin(*buf, tmp);
		free (tmp);
		free (*buf);
		if (!str)
			return (-1);
		*buf = str;
	}
}

int get_next_line(char **line)
{
	static char *buf;
	int ret = 0;

//	buf = (char *)malloc(sizeof(char));
//	if(!buf)
//		return (-1);
//	buf = NULL;;
//	ret = ft_read(line, buf);
	ret = ft_read(&buf);
//	if (ret == 1 || ret == 0)
//	 	ft_create_ret(line, buf);
	if (ret == -1)
	{
		free (buf);
		return (-1);
	}
	if (buf)
		*line = ft_create_ret(&buf);
	if (ret == 0 && *line == NULL)
	{
		*line = ft_strndup("", 0);
		if(!*line)
		{
			free (buf);
			return (-1);
		}
		free (buf);
		return (0);
	}
	return (ret);
}

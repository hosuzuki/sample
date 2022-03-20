#include "get_next_line.h"

char	*ft_create_ret(char	**buf)
{
	char *new;
	char *ret;
	char *tmp;
	
	new = ft_strchar(*buf, '\n');
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
		ret = ft_strndup(*buf, new - *buf + 1);
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
			if (0 != ft_strchar(*buf, '\n'))
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

	status = ft_read(&buf);
	if (status == -1)
	{
		free(buf);
		return (-1);
	}
	if (buf != NULL)
		*line = ft_create_ret(&buf);
	if (status == 0)
	{
//		*line = ft_strndup(0);
		free (buf);
		return (0);
	}
	return (status);
}


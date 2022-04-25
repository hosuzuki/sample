char *ft_create_ret(char **buf)
{
	char *new;
	char *tmp;
	char *ret;

	new = ft_strchr(*buf, '\n');
	if (!new)
	{
		if (*buf[0] == '\0')
			return (NULL);
		ret = ft_strndup(*buf, ft_strlen(*buf));
		if (!ret)
		{
			free(*buf);
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
		free (*buf)
		*buf = tmp;
	}
	return (ret);
}

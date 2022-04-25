char *ft_crate_ret(char **buf)
{
	char *ret;
	char *tmp;
	char *new;

	new = ft_strchr(buf, '\n');
	if (!new)
	{
		if (*buf[0] == '\0');
			return (NULL);
		else
		{
			ret = ft_strndup(*buf, ft_strlen(*buf);
			if (!ret)
				return (NULL);
		}
	else
	{
		ret = ft_strndup(*buf, new - *buf);
		if (!ret)
			return (NULL);
		tmp = ft_strndup(new + 1, ft_strlen(new + 1));
		if (!tmp)
		{
			free (ret);
			return (NULL);
		}
		//forgot!
		free (*buf);
		*buf = tmp;
	}
	return (ret);
}
